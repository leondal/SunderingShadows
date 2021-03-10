#include <std.h>

inherit OBJECT;

string file;
object doer, target;
string args;
string func;

void create(){
    ::create();
}

set_file(string f){
    file = f;
}

set_doer(object x){
    doer = x;
}

set_target(object x){
    target = x;
}
set_args(mixed *a){
    args = a;
}

set_function(string f){
    func = f;
}

execute_attack(){
    object ob = find_object_or_load(file);
    if (objectp(ob)) {
        if (objectp(target)) {
            call_other(ob,func,doer,target,args);
        } else {
            call_other(ob,func,doer,args);
        }
    }
    remove();

}

