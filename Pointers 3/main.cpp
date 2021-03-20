class MyClass
{
public:
    int m_Number;
    char m_Character;
};

int main()
{
    MyClass *pPointer;
    pPointer = new MyClass;

    pPointer->m_Number = 10;
    pPointer->m_Character = 's';

    delete pPointer;
    return 0;
}