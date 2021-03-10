#include <std.h>

object *all_present(string what, object ob){

        object *ret, *inven;
        int i;
        
        ret = ({});
        inven = all_inventory(ob);
        for (i=0;i<sizeof(inven);i++){
                if (inven[i]->id(what)){
                        ret += ({inven[i]});
                } 
        }                
        
        return ret;

}
