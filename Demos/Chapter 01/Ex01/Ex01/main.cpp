/*
 * Ex01 - The default constructor demonstration 
 *
 * Written by: Ilan Amoyal
 *
 */

class ClassA
{
	/* A default constructor is generated automatically by the comipler. */
};

class ClassB
{
public:
	ClassB(int dummy){ }
	/* This class has NO default constructor */
};

class ClassC
{
public:
	ClassC(){ }
	ClassC(int dummy){ }
	/* This class has a default constructor because it was declared explicitly. */
};

int main(int argc, char *argv[])
{
	ClassA a;
	// ClassB b; this line executes a compilation error
	ClassC c;
}