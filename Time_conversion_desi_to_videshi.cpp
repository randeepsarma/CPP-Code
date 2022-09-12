string timeConversion(string str) {
    int index=str.length()-2;
string t ="";
for(int i=2;i<index;i++){
   t+=str[i];
}string first="";    
if(str[index]=='A'){
    int tt=(str[0]-'0')*10+str[1]-'0';
    if(str[0]=='1' && str[1]=='2'){
        first="00";
    }else {
     if(str[0]=='1')   
    first=to_string(tt);
    else first='0'+to_string(tt);
    }
}else if(str[index]=='P'){
    int tt=(str[0]-'0')*10+str[1]-'0';
    if(str[0]=='1' && str[1]=='2'){
        first="12";
    }else {
    tt+=12;
    first=to_string(tt);
}}
    
    return first+t;
}
