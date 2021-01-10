/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* aName) : value(v), name(aName){}   //1 √
    int value;//2 √
    std::string name; //3 √
};

struct CompareStruct                            //4 √
{
    T* compare(T& a, T& b) //5 √
    {
    
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float u1 { 0.f }, u2 { 0.f };
    float aMathFunction(const float& newVal)      //12
    {
            std::cout << "U's u1 value: " << this->u1 << std::endl;
            this->u1 = newVal;  
            std::cout << "U's u1 updated value: " << this->u1 << std::endl;

            while( std::abs(this->u1 - this->u2) > 0.001f )
            {
                this->u2 += 1.0f;
                
            }
            std::cout << "U's u2 updated value: " << this->u2 << std::endl;
            return this->u2 * this->u1;   
    }
};

struct X
{
    static float aStaticFunction (U& that, float& newVal )        //10 √
    {
       
        
        std::cout << "U's u1 value: " << that.u1 << std::endl;
        that.u1 = newVal;
        std::cout << "U's u1 updated value: " << that.u1 << std::endl;

        while( std::abs(that.u1 - that.u2) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            //std::cout<< that->u2;
            that.u2 += 0.1f;
        }

        std::cout << "U's u2 updated value: " << that.u2 << std::endl;
        return that.u2 * that.u1;
        

    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(1.0f ,"a");                                             //6 √
    T t2(2.0f ,"b");                                             //6 √
    
    CompareStruct f;                                            //7 √
    auto* smaller = f.compare( t1 , t2  );                              //8 √

    if(smaller != nullptr)
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9 √
    
    U uu1;
    float updatedValue = 5.f;
    std::cout << "[static func] uu1's multiplied values: " << X::aStaticFunction(uu1 , updatedValue ) << std::endl;                  //11 √
    
    U uu2;
    std::cout << "[member func] uu2's multiplied values: " << uu2.aMathFunction( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
