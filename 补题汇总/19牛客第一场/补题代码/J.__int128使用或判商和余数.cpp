__int128 x,a,y,b;
void check(char now) {if(now==EOF) exit(0);}
 
void read(__int128 &x) {
    x=0; __int128 f=1;
    char ch=getchar();check(ch);
    if(ch=='-') f=-f; else x=x*10+ch-'0';
    while(1) {
        ch=getchar();check(ch);
        if(ch>='0'&&ch<='9') x=x*10+ch-'0';
        else break;
    }x*=f;
}
void _print(__int128 x) {
    if(x>9) _print(x/10);
    putchar(x%10+'0');
}
void print(__int128 x) {
    if(x<0) { x=-x;putchar('-');}
    _print(x);
}
 
int main() { 
    while(1) {
            read(x);
            read(a);
            read(y);
            read(b);
            if ( x*b==y*a )
                cout<<'=';
            else if ( x*b<y*a )
                cout<<'<';
            else
                cout<<'>';
            cout<<endl;
        }
    return 0;
}
