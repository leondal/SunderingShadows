#include <std.h>
#include <security.h>
#include <objects.h>

inherit OB_USER;

void restore_user(string user);

varargs mixed user_call(string user, string func, mixed arg1, mixed arg2, mixed arg3, mixed arg4){
    mixed res;
    object ob = find_player(user);
    if(objectp(ob)) {
        return call_other(ob, func, arg1, arg2, arg3, arg4);
    }

    restore_user(user);

    return call_other(this_object(),func, arg1, arg2, arg3, arg4);
}

private void restore_user(string user){
    string path;
    if(!user_exists(user)) return;
    seteuid(UID_ROOT);
    path = "/adm/save/users/";
    path += user[0..0]+"/";
    path += user;
    restore_object(path);

}
