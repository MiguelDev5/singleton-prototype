#include <iostream>

using namespace std;

class FooManager{
public:
    int GetSampleData(){
        return SampleData;
    }
    static void Create(){
        if (m_Inst == 0){
            m_Inst = new FooManager();
        }
    }
    static FooManager* GetInst(){
        return m_Inst;
    }
protected:
    FooManager();
    virtual ~FooManager();

private:
    int SampleData;
    static FooManager* m_Inst;

};

FooManager* FooManager::m_Inst = 0;

FooManager::FooManager(): SampleData(100){

}

FooManager::~FooManager(){}

int main(){
    cout << "Patron singleton" << endl;
     
    FooManager::Create();

    FooManager* pMyFoo1 = FooManager::GetInst();

    if(pMyFoo1 != 0){
        cout << "primera instancia Inst sample data: " << pMyFoo1->GetSampleData() << endl;
        cout << pMyFoo1 << endl;
    }

    FooManager* pMyFoo2 = FooManager::GetInst();
    if(pMyFoo2 != 0){
        cout << "¿Segunda instancia? Inst sample data: " << pMyFoo2->GetSampleData() << endl;
        cout << pMyFoo2 << endl;
    }
};
