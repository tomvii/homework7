#include"calcu.h"
using namespace std;
int main(int argc, char *argv[])
{
	equation eq;
	file f;
	int u, z;
	char *p = argv[1];
	char *pu = argv[2];
	int total;
	total = f.fileread(p);
	f.boundary(eq, pu);
	u = eq.test(total, pu);
	z = total - u;
	eq.print(u, z);
	system("pause");
	return 0;
}
