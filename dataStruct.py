class Robot():
    """ Definition of Class"""

    population = 0

    def __init__(self, name):
        self.name = name
        print("Creating Robot {}." .format(self.name))

        Robot.population += 1

    def die(self):
        print("Destroying Robot {}." .format(self.name))
        Robot.population -= 1

        if Robot.population == 0:
            print("{} was the last Robot." .format(self.name))
        else:
            print("There are still {:2} Robots." .format(Robot.population))

    def intro(self):
        """ Introduction from Class """
        print("Hello from {}!" .format(self.name))

    @classmethod
    def number(cls):
        print("The remaining Robots are {}." .format(cls.population))


class SchoolMember():
    def __init__(self, name, age):
        self.name = name
        self.age = age
        print("Initializing Member {}." .format(self.name))

    def details(self):
        print("Name: {} and Age {}" .format(self.name, self.age), end=" ")


class Teacher(SchoolMember):
    def __init__(self, name, age, salary):
        SchoolMember.__init__(self, name, age)
        self.salary = salary
        print("Initialized Teacher {}." .format(self.name))

    def details(self):
        SchoolMember.details(self)
        print("and Salary {:d}" .format(self.salary))


class Student(SchoolMember):
    def __init__(self, name, age, marks):
        SchoolMember.__init__(self, name, age)
        self.marks = marks
        print("Initialized Student {}." .format(self.name))

    def details(self):
        SchoolMember.details(self)
        print("and Marks {}." .format(self.marks))


def reverse(str):
    return str[ : : -1]


def palindrome(str):
    return str == reverse(str)


class ShortInputException(Exception):
    def __init__(self, length, minLength):
        Exception.__init__(self)
        self.length = length
        self.minLength = minLength


if __name__ == "__main__":

    if 0:
        droid1 = Robot("R2-D2")
        droid1.intro()
        Robot.number()

        droid2 = Robot("C-3PO")
        droid2.intro()
        Robot.number()

        droid1.die()
        droid2.die()
        Robot.number()

    else:
        t = Teacher("Urmi", 35, 150000)
        s = Student("Raj", 30, 99)

        print()

        members = [t, s]
        for mem in members:
            mem.details()

        try:
            str = input("Input a String: ")
            if len(str) < 3:
                raise ShortInputException(len(str), 3)

        except EOFError:
            print("You pressed EOF!")

        except ShortInputException as ex:
            print("Short Exception Error!")

        else:
            res = palindrome(str)
            print(res)
