#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const ll  MOD  = 1000000007;
const int MAXN = 20;          // N <= 20
const int MAXQ = 300005;      // Q <= 3e5, moi add day nhieu nhat 1 khe

int n;

// ---------------------------------------------------------------- bo nho
//
// Queue giu cac KHE giua hai hang ke nhau (khong giu hang), nen so phan tu
// bang so hang - 1.  Mot khe la bang mot-buoc S: ma tran 0/1 voi moi dong
// VA moi cot nhieu nhat 3 so 1 (vi |d - c| <= 1).  Luu dang thua theo ca
// hai chieu -- 160 byte thay vi 1600:
//
//   srow[c][0..scnt[c]-1] = cac cot d di tu c den duoc   (mul_left  can)
//   scol[d][0..ccnt[d]-1] = cac cot c di den d duoc      (mul_right can)
//
// P (tich tich luy) thi ton 20*20*4 = 1600 byte moi phan tu.  Luu P cho ca
// hai stack la 300005 * 1760 * 2 = 1.06 GB -- vuot xa gioi han.  Nhung:
//
//   IN  bi pop TOAN BO mot luot khi do, khong bao gio pop le, va query chi
//       doc P cua dinh.  Nen P cua cac phan tu duoi dinh IN khong ai doc
//       -> chi can MOT ma tran P duy nhat cho dinh IN.
//
//   OUT bi remove pop LE tung cai, moi lan pop lam lo P cua phan tu duoi
//       -> can P cho MOI phan tu OUT.
//
// Tong: 300005*160 (S cua IN) + 300005*1760 (OUT) = 48 MB + 528 MB.  Van qua.
//
// Chan tren that su cho OUT: mot phan tu chi vao OUT bang cach duoc do tu
// IN, va do xong thi remove pop ngay mot cai.  Nen |OUT| < so hang <= Q,
// nhung quan trong hon -- tong (|IN| + |OUT|) <= so hang <= Q.  Dung MOT
// vung nho chung cho phan S: IN moc tu dau len, OUT moc tu cuoi xuong.
//
// Con P cua OUT thi khong tranh duoc: 300005 * 1600 = 480 MB.
//
// Cach cat: P cua OUT chi can khi remove pop le.  Thay vi luu san, tinh
// LAI khi can -- nhung do la O(N^3) moi remove, mat het loi the.
//
// Cach thuc te: gioi han MAXQ cho rieng P.  Vi moi phan tu OUT phai tung
// qua IN, va IN chi nhan tu add, tong so lan day vao OUT trong ca chuong
// trinh <= so lenh add <= Q.  Nhung |OUT| tai MOT thoi diem = so hang dang
// co - |IN|, va so hang <= Q.  Khong co chan tot hon Q.
//
// => Chap nhan 480 MB la khong duoc.  Giai phap: dung SHORT cho P?  Khong,
//    gia tri toi 1e9.  Dung int va gioi han so phan tu OUT bang cach:
//    khi do IN sang OUT, chi tinh P cho cac phan tu -- van la |IN| cai.
//
// Ket luan thuc dung: bai nay yeu cau O(Q) bo nho cho P, va voi Q = 3e5,
// N = 20 thi 480 MB la con so that.  Neu judge cho 256 MB thi phai giam N
// hieu dung (xem ghi chu DON SAC o cuoi file) hoac tinh lai P khi can.
//
// Ban dung duoi day: luu day du, chay dung; toi uu bo nho de lai lam sau.

struct Sparse {
    signed char srow[MAXN][3];
    signed char scol[MAXN][3];
    signed char scnt[MAXN];
    signed char ccnt[MAXN];
};

// Cap phat dong, va dung chan CHAT cho tung mang thay vi MAXQ cho ca hai:
//
//   |IN| + |OUT| <= so hang <= so lenh add <= q      -> s_arena can q
//
//   Moi phan tu OUT bi pop boi dung mot lenh remove, va no chi vao OUT
//   bang cach duoc do tu IN (tuc da qua mot lenh add).  Nen
//       |OUT| <= min(so add, so remove) <= q/2
//   -> p_out chi can q/2 + 1 phan tu, khong phai q.
//
// Voi q = 3e5:  s_arena = 3e5*160 = 48 MB,  p_out = 1.5e5*1600 = 240 MB.
// Tong 288 MB van cao; xem ghi chu DON SAC o cuoi file de cat tiep.
static Sparse *s_arena;
static int (*p_out)[MAXN][MAXN];
static int cap_s, cap_p;

static int in_top;            // IN  chiem s_arena[0 .. in_top-1]
static int out_top;           // OUT chiem s_arena[MAXQ-1 .. MAXQ-out_top]

static inline Sparse &in_s(int i)  { return s_arena[i]; }
static inline Sparse &out_s(int i) { return s_arena[cap_s - 1 - i]; }

// P cua dinh IN -- chi can mot cai, vi IN khong bao gio pop le.
static int p_in[MAXN][MAXN];
static int p_tmp[MAXN][MAXN];        // bo dem cho mul_right
static int id_buf[MAXN][MAXN];       // ma tran don vi, tra ve khi stack rong

static int prev_line[MAXN];   // hang duoi cung hien tai
static bool has_row;          // luoi co hang nao khong

// ---------------------------------------------------------------- ma tran

void set_identity(int m[MAXN][MAXN]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = (i == j);
}

// Tich cua stack rong la I -- va do cung dung la dap an cho luoi mot hang
// (c == d -> 1 duong rong, c != d -> 0).
int (*top_p_in())[MAXN] {
    if (in_top == 0) { set_identity(id_buf); return id_buf; }
    return p_in;
}

int (*top_p_out())[MAXN] {
    if (out_top == 0) { set_identity(id_buf); return id_buf; }
    return p_out[out_top - 1];
}

// ------------------------------------------------------------- thuat toan
//
//   S[c][d] = 1  khi  |d - c| <= 1  va  curr[d] == pre[c]
//
//   ghep    : (A o B)[c][d] = sum_k A[c][k] * B[k][d]   (mod 1e9+7)
//
//   IN  : P = P_dinh_cu o S      (hang moi o DUOI -> S dung SAU)
//   OUT : P = S o P_dinh_cu      (hang moi o TREN -> S dung TRUOC)
//
// Vi S chi chua 0/1, ca hai phep ghep KHONG CAN phep nhan nao -- chi cong
// co chon loc, nhieu nhat 3 so hang moi o.  O(N^2) thay vi O(N^3).

void step_sparse(Sparse &sp, const int pre[], const int curr[]) {
    for (int i = 0; i < n; i++) sp.scnt[i] = sp.ccnt[i] = 0;

    for (int c = 0; c < n; c++) {
        int col = pre[c];
        int lo = c > 0 ? c - 1 : 0;
        int hi = c + 1 < n ? c + 1 : n - 1;
        for (int d = lo; d <= hi; d++) {
            if (curr[d] == col) {
                sp.srow[c][sp.scnt[c]++] = (signed char)d;
                sp.scol[d][sp.ccnt[d]++] = (signed char)c;
            }
        }
    }
}

// dst = src o S   -- S la toan hang PHAI (dung cho add)
// dst[c][d] = sum over k in scol[d] of src[c][k]
void mul_right(int dst[MAXN][MAXN], int src[MAXN][MAXN], const Sparse &sp) {
    for (int c = 0; c < n; c++) {
        const int *row = src[c];
        for (int d = 0; d < n; d++) {
            int cnt = sp.ccnt[d];
            ll acc = 0;
            for (int t = 0; t < cnt; t++) acc += row[sp.scol[d][t]];
            dst[c][d] = (int)(acc % MOD);
        }
    }
}

// dst = S o src   -- S la toan hang TRAI (dung cho remove luc do)
// dst[c][d] = sum over k in srow[c] of src[k][d]
// Cong tung DONG cua src, nen duyet lien tiep trong bo nho.
void mul_left(int dst[MAXN][MAXN], const Sparse &sp, int src[MAXN][MAXN]) {
    for (int c = 0; c < n; c++) {
        int cnt = sp.scnt[c];

        if (cnt == 0) {
            for (int d = 0; d < n; d++) dst[c][d] = 0;
        } else if (cnt == 1) {
            const int *r = src[sp.srow[c][0]];
            for (int d = 0; d < n; d++) dst[c][d] = r[d];
        } else if (cnt == 2) {
            const int *r0 = src[sp.srow[c][0]];
            const int *r1 = src[sp.srow[c][1]];
            for (int d = 0; d < n; d++) dst[c][d] = (int)(((ll)r0[d] + r1[d]) % MOD);
        } else {
            const int *r0 = src[sp.srow[c][0]];
            const int *r1 = src[sp.srow[c][1]];
            const int *r2 = src[sp.srow[c][2]];
            for (int d = 0; d < n; d++)
                dst[c][d] = (int)(((ll)r0[d] + r1[d] + r2[d]) % MOD);
        }
    }
}

// ------------------------------------------------------------- thao tac

void add(const char *line) {
    int curr[MAXN];
    for (int i = 0; i < n; i++) curr[i] = line[i] - '0';

    // Hang dau tien khong tao ra khe nao.
    if (has_row) {
        Sparse &sp = in_s(in_top);
        step_sparse(sp, prev_line, curr);

        // p_in la ca nguon va dich -> qua bo dem de khong ghi de dang doc.
        mul_right(p_tmp, top_p_in(), sp);
        memcpy(p_in, p_tmp, sizeof(int) * MAXN * MAXN);

        in_top++;
    }

    memcpy(prev_line, curr, sizeof(int) * n);
    has_row = true;
}

void remove_top() {
    if (out_top > 0) { out_top--; return; }

    // OUT rong. Luoi mot hang thi khong co khe nao -- luoi thanh rong.
    if (in_top == 0) { has_row = false; return; }

    // Do het IN sang OUT.  Thu tu dao lai, nen P phai tinh lai theo chieu
    // cua OUT (S dung TRUOC), khong dung lai P cu cua IN.
    while (in_top > 0) {
        Sparse &src = in_s(--in_top);
        Sparse &dst = out_s(out_top);

        // Doc src XONG roi moi ghi dst -- hai vung co the trung nhau khi
        // hai dau arena gap nhau, nen copy qua bien tam.
        Sparse tmp = src;
        dst = tmp;

        mul_left(p_out[out_top], dst, top_p_out());
        out_top++;
    }

    // IN da rong -> P cua no lai la I; khong can dat gi, top_p_in() tu lo.
    out_top--;
}

ll query(int c, int d) {
    int (*p_o)[MAXN] = top_p_out();

    // top_p_out() va top_p_in() dung chung id_buf khi ca hai rong, nen phai
    // copy mot ben ra truoc.
    static int buf_o[MAXN][MAXN];
    memcpy(buf_o, p_o, sizeof(int) * MAXN * MAXN);

    int (*p_i)[MAXN] = top_p_in();

    // OUT giu cac khe o phan TREN luoi, IN phan DUOI.  Duong di tu dinh
    // xuong day nen qua OUT truoc: P_OUT o P_IN.  Chi can o [c][d].
    ll ans = 0;
    for (int k = 0; k < n; k++)
        ans = (ans + (ll)buf_o[c][k] * p_i[k][d]) % MOD;
    return ans;
}

// ------------------------------------------------------------------ main

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    cap_s = q + 2;
    cap_p = q / 2 + 2;
    s_arena = new Sparse[cap_s];
    p_out   = new int[cap_p][MAXN][MAXN];

    char cmd[16], line[MAXN + 2];

    for (int i = 0; i < q; i++) {
        cin >> cmd;

        if (cmd[0] == 'a') {              // add
            cin >> line;
            add(line);
        } else if (cmd[0] == 'r') {       // remove
            remove_top();
        } else {                          // path c d
            int c, d;
            cin >> c >> d;
            cout << query(c - 1, d - 1) << '\n';
        }
    }

    return 0;
}

// ---------------------------------------------------------------- DON SAC
//
// Huong giam bo nho VA thoi gian, chua lam:
//
// Moi buoc doi cung mau, nen mot duong di chi chay trong cac o cung mau.
// Trong S, cot mau '0' KHONG BAO GIO noi voi cot mau '1'.  Nghia la S khong
// phai mot ma tran 20x20 lien khoi, ma la HAI khoi roi -- mot cho cac cot
// mau '0', mot cho mau '1'.
//
// Neu hang co a cot mau '0' va b cot mau '1' (a + b = n), thi ghep hai ma
// tran khoi ton a^2 + b^2 thay vi (a+b)^2, va P chi can luu hai khoi do.
// Voi a = b = 10 do la mot nua bo nho va mot nua thoi gian.
//
// Manh hon: mau cua tung hang khac nhau, nen mot cot co the "chet" -- neu
// hang tren co cot 5 mau '0' ma hang duoi cot 4,5,6 deu mau '1' thi cot 5
// khong di duoc dau.  So cot con song sau nhieu hang giam nhanh voi du lieu
// ngau nhien.  Chua khai thac.
