#include <std.h>

int cmd_keep(string str)
{
    object obj;

    if (!(obj = present(str, TP))) {
        tell_object(TP,"%^BOLD%^%^RED%^You don't have any " + str + ".");
        return 1;
    }

    if (!obj->query_property("nosell")) {
        tell_object(TP,"%^BOLD%^%^WHITE%^" + obj->query_short() + "%^BOLD%^%^RED%^ can no longer be sold.
Use <keep> again to unmark it. ");
        obj->set_property("nosell", 1);
    } else {
        tell_object(TP,"%^BOLD%^%^RED%^You can sell " + obj->query_short() + "%^BOLD%^%^RED%^ again.");
        obj->remove_property("nosell");
    }

    return 1;
}

help()
{
    write("
%^CYAN%^NAME%^RESET%^

keep - prevent something from being sold

%^CYAN%^SYNTAX%^RESET%^

keep %^ORANGE%^%^ULINE%^OBJECT%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command marks and unmarks an object the way it won't be sold if you accidently suggest it to vendor.

%^CYAN%^SEE ALSO%^RESET%^

shop, inventory, eq, look, steal, money
");
}
