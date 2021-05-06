#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

bool fn_IsLegal(std::stack<char>& or_St, char& c_In, char* cp_Arr, int i_Size);
int fn_GetIndex(char& c_In, char* cp_Arr, int i_Size);

int main(){
    std::stack<char> o_St;
    char ca_DeNo[6]     = {'{', '[', '(', '}', ']', ')'};
    std::string s_Cin   = "";
    std::cin >> s_Cin ;

    bool b_IsLegal      = true;
    for(int i_Ct=0; i_Ct < s_Cin.length() &&
            b_IsLegal; i_Ct++){
        b_IsLegal       = fn_IsLegal(o_St, s_Cin[i_Ct], ca_DeNo, sizeof(ca_DeNo)/sizeof(char));
    }

    if(b_IsLegal && o_St.empty() == true){
        std::cout<< "True";
    }
    else{
        std::cout<< "False";
    }

    return 0;
}

bool fn_IsLegal(std::stack<char>& or_St, char& c_In, char* cp_Arr, int i_Size){
    bool b_IsLegal      = true;
    int i_Ind           = -1;
    i_Ind               = fn_GetIndex(c_In, cp_Arr, i_Size);

    if(i_Ind == -1){
        exit(1);
    }

    if(i_Ind< (i_Size/2)){
        or_St.push(c_In);
    }
    else{
        i_Ind           %= 3;
        if(or_St.top() == cp_Arr[i_Ind]){
            or_St.pop();
        }
        else{
            b_IsLegal   = false;
        }
    }


    return b_IsLegal;
}

int fn_GetIndex(char& c_In, char* cp_Arr, int i_Size){
    int i_Ind           = -1;

    for(int i_Ct=0; i_Ct< i_Size; i_Ct++){
        if(cp_Arr[i_Ct] == c_In){
            i_Ind       = i_Ct;
            break;
        }
    }
    return i_Ind;
}
