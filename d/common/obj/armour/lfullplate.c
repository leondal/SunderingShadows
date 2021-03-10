inherit "/d/common/obj/armour/fullplate";

void create() 
{
    ::create();
    set_name("fullplate");
     set_id(({ "armor","full plate armor","plate","large fullplate"}));
    set("short", "A suit of large full plate armor");
    set("long", 
        "This is the impressive, high gothic style armor of the late "
"middle ages and renaissance. It is perfectly forged and fitted. All the  "
"plates are interlocking and carefully angled to deflect blows. The metal "
"plates are backed by padding and chainmail. The weight is well " 
"distributed. The armor is hot and extremely expensive."
       );
//    set_weight(50);
    set("value", 15000);
//    set_type("armour");
//    set_limbs( ({ "torso" }) );
//    set_ac(9);
   set_size(3);
}

int is_metal() { return 1; }