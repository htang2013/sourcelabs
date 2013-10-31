template <class Object>
class List;

template <class Object>
class ListItr;

template <class Object>
class ListNode
{
    Object element;
    ListNode(const Object &theElement = Object(), 
             ListNode *n = NULL): element(theElement), next(n) {}
    ListNode *next;
    friend class List <Object>;
    friend class ListItr <Object>;
};
   
    



