int createNum();
void putNum(int a);

int sum(int a,int b)
{
    return a+b;
}

int main()
{
    int x=createNum();
    int y=createNum();
    int z=sum(x,y);
    putNum(z);
    return 0;
}
// 预处理 编译 汇编 链接
//   -E .i    -S.s  .o
//  编译成目标文件
// g++ -c -o main.o main.cpp
// g++ -c -o sum.o sum.cpp 
//  链接所有的目标文件 生成可执行文件
// g++ -o main main.o sum.o
//  执行
// ./main 