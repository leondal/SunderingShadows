#include <std.h>

inherit BBOARD;

int valid_user(object obj)
{
    if(obj->is_class("assassin"))
        return 1;
    if(obj->query("is_assassin"))
        return 1;
    if(avatarp(obj))
        return 1;
    return 0;
}
