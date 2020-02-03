#include <iostream>
#include "alarm.h"

using namespace std;

//float global_var_x {2.0};
//int global_var_y {};
//int global_var_z;
//const int global_const_aux{10};
//static float global_static {3.0};
//auto global_auto{2};
//static auto global_auto_const {4.9};

ostream& operator<<(ostream& os, Alarm& alarm)
{
   os << alarm.as_string();
   return os;
}

int main()
{
//    int local_var {1};
//    static int local_static{2};

//    cout << hex << endl;
//    cout << "Local_var: " << &local_var << endl;
//    cout << "Local_static: " << &local_static << endl;

//    cout << "Initialised global: " << &global_var_x << endl;
//    cout << "Uninitialised global: " << &global_var_y << endl;
//    cout << "Zero initialised global: " << &global_var_z<< endl;
//    cout << "Const global: " << &global_const_aux << endl;
//    cout << "Static global: " << &global_static << endl;
//    cout << "Automatic global: " << &global_auto << endl;
//    cout << "Static Automatic global: " << &global_auto_const << endl;

//    cout << "Main: " << reinterpret_cast<int*>(&main)<< endl;

    Alarm a1{};
    Alarm a2{Alarm::caution};

    a1.print_state();
    a2.print_state();

    cout<< "a1: " << a1.as_string() << endl;
    cout<< "a2: " << a2.as_string() << endl;

    cout << "Done!" << endl;
    return 0;
}
