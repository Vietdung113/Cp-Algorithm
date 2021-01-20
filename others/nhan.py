class Country:
    """Super Class"""

    def show_sup_class(self):
        print('This is Country Class method! <<test 1>>')
        print('Let me know', '1. CountryName', '2. PopulationSize', '3. CapitalCity <<test 2>>')

    def print_inheritance(self):
        print('This is a code for the inheritance test. <<test 3>>')


class WhichCountry(Country):
    """Sub Class"""

    def __init__(self, name):
        self.name = name

    def show_name(self):
        print('To test method overriding : <<test 4>>', self.name)


class WhichCountry(Country):
    """Sub Class"""

    def __init__(self, name, population, capital):
        self.name = name
        self.population = population
        self.capital = capital

    def show(self):
        print('To show parent class method. <<test 5>>')
        super().show_sup_class()
        print(
            """
            Country name is {} .
            Population Size is {} .
            Capital City is {} <<test 6>>.
            """.format(self.name, self.population, self.capital)
        )


print('This is a case of China.')
a2 = WhichCountry('China', 1300000000, 'Beijing')
a2.show()
a2.print_inheritance()
