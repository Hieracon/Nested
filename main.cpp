#include <list>
#include <iostream>

using namespace std;

class listOp{
private:
    list<int> intList;

public:
    friend class modify_list;

    void add_element(int x){
        intList.push_back(x);
    }

    class Display{
    public:
        void showlist(listOp e){
            for(auto it : e.intList){
                cout<<"   "<<it;
            }
            cout<<endl;
        }
    };

};

class modify_list{
public:
    void delete_element_at_position(int y, listOp *e){
        list<int>::iterator it;
        it = e->intList.begin();
        advance(it, y);
        e->intList.erase(it);
    }

    void delete_elements(int z, listOp *e){
        e->intList.sort();
        while (true){
            if(e->intList.front() < z){
                e->intList.pop_front();
            }
            else{
                break;
            }
        }
    }

    int average(listOp e){
        int sum = 0;
        int count = 0;
        double result;

        for(auto it : e.intList){
            count++;
            sum = sum + it;
        }

        result = sum/count;

        return result;
    }
};



int main()
{
    int verify;
    listOp obj;
    listOp::Display obj_1;
    modify_list obj_2;

    do{
        cout<<"Press 1 to add an elemnt."<<endl;
        cout<<"Press 2 to delete an element at a position."<<endl;
        cout<<"Press 3 to delete all elements that are less than a number that you choose."<<endl;
        cout<<"Press 4 to get the average of the numbers in the list."<<endl;
        cout<<"Press 5 to dispaly the list."<<endl;
        cout<<"Press 6 to exit."<<endl;

        cin>>verify;

        if(verify == 1){
            int temp;
            cout<<"The element you want to add to the list is:";
            cin>>temp;
            obj.add_element(temp);
        }
        else{
            if(verify == 2){
                int temp;
                cout<<"The element you want to delete from the list is at position number:";
                cin>>temp;
                temp--;
                obj_2.delete_element_at_position(temp, &obj);
            }
            else{
                if(verify == 3){
                    int temp;
                    cout<<"The element is:";
                    cin>>temp;
                    obj_2.delete_elements(temp, &obj);
                }

                else{
                    if(verify == 4){
                        cout<<"The average is:"<<obj_2.average(obj)<<endl;
                    }

                    else{
                        if(verify == 5){
                            obj_1.showlist(obj);
                        }

                        else{
                            return 0;
                        }
                    }
                }
            }

        }
        cout<<endl;
    }while(1==1);

    return 0;
}
