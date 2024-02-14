/* 1. The process of the machine does not matter for comparing these two solutions, but having a better proccessor results in 
a faster run time for anything. 
2. The std::vector preforms better for this problem since it is an array and you do not need to traverse the entire thing for 
look ups or to delete. 
3. N being larger will be slower than M since M is always less than N */
#include "TestListMyJosephus.h"
#include "TestVectorMyJosephus.h"
int main(){
    TestListMyJosephus();
    TestVectorMyJosephus();
}