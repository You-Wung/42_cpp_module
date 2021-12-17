#include "ShrubberyCreationForm.hpp"

void										ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	executable(b);
	std::ofstream		out(getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	//out - write	trunc - if there's, erase then make
	if (!out.good())
	{
		std::cout << "Error Occurred. File " << getName() << "_shrubbery can not be made.\n";
		return ;
	}
	std::string			shrubbery =	"            .        +          .      .          ..\n"
									"     .            _        .                    .\n"
									"  ,              /;-._,-.____        ,-----.__\n"
									" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
									"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
									"                      ,    `./  \\:. `.   )==-'  .\n"
									"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
									".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
									"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
									"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
									"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
									"              \\:  `  X` _| _,\\/'   .-'\n"
									".               \":._:`\\____  /:'  /      .           .\n"
									"                    \\::.  :\\/:'  /              +\n"
									"   .                 `.:.  /:'  }      .\n"
									"           .           ):_(:;   \\           .\n"
									"                      /:. _/ ,  |\n"
									"                   . (|::.     ,`                  .\n"
									"     .                |::.    {\\\n"
									"                      |::.\\  \\ `.\n"
									"                      |:::(\\    |\n"
									"              O       |:::/{ }  |                  (o\n"
									"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
									"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
									"tyou  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~\n";
	out << shrubbery;
	out.close();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	return (*(dynamic_cast<ShrubberyCreationForm *>(&(Form::operator=(s)))));
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	Form()
{
	setType(S_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	Form(target, S_SIGN, S_EXEC)
{
	setType(S_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
	:	Form(s)
{
	setType(S_NAME);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}