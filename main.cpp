#include <iostream>
#include "inf_int.h"
#include "inf_int_test.h"

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    inf_int_test::TestDefault();
    inf_int_test::TestOperate100digitsWith50digits();

    return 0;
}
