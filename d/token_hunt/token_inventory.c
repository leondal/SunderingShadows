#include <std.h>
#include "/d/token_hunt/token_hunt.h"
#include <security.h>

inherit OBJECT;

#define SAVE_FILE INV_PATH"inventory"

mapping INVENTORY;

void create()
{
    INVENTORY = (["high" : ([]),
                  "mid"  : ([]),
                  "low"  : ([]),]);
    ::create();
    restore_object(SAVE_FILE);
}

object get_inventory_object() { return TO; }
mapping get_inventory() { return INVENTORY; }
void set_inventory(mapping map) { INVENTORY = map; }
void save_inventory() 
{ 
    seteuid(geteuid());
    save_object(SAVE_FILE); 
}
int clean_up() { return 1; }
void reset() { return 1; }
