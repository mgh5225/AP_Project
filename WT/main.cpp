#include "index.h"
#include<Wt/Json/Object.h>
int main(int argc, char** argv)
{
	return Wt::WRun(argc, argv, [](const WEnvironment & env){
		return make_unique<index>(env);
		});
}