#include <std.h>

object deep_present(mixed str, object ob){
    int i,j;
    int count, desired;
    string x;
    object * inven;
    inven = deep_inventory(ob);

    if (objectp(str)) {
        j = sizeof(inven);
        for (i = 0;i < j;i++) {
            if (ob == inven[i]) {
                return inven[i];
            }
        }
        return 0;
    }
    sscanf(str, "%s %d", x, desired);
    if (!desired) {
        desired = 1;
    }
    j = sizeof(inven);
    for (i =0;i < j;i++) {
        if (inven[i]->id(x)) {
            count++;
            if (count == desired) {
                return inven[i];
            }
        }
    }
    return 0;

}

