#include <stdio.h>
#define print_my_name printf("> %s\n", __FUNCTION__);

/* FUNCTION DECL*/
void a(void);
void b(void);
void c(void);
void d(void);
void e(void);
void f(void);
void g(void);
void h(void);
void i(void);
void j(void);
void k(void);

/* Main */
int main(){
    print_my_name;

    c();
    f();
    return 0;
}

void c(void){
	print_my_name;
 
    b();
    d();      
}

void b(void){
	print_my_name;
 
    a();
}

void d(void){
	print_my_name;
};

void a(void){
	print_my_name;
};

void f(void){
	print_my_name;
 
    g();
    i();
}

void g(void){
	print_my_name;
    h();
};

void h(void){
	print_my_name;
};

void i(void){
	print_my_name;
 
    j();
    k();
}

void j(void){
	print_my_name;
};

void k(void){
	print_my_name;
};

