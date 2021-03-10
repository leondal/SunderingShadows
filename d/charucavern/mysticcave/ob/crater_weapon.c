#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
#define COM "/d/common/obj/weapon/"

inherit "/d/common/obj/weapon/bardiche";

string dam_bonus, item_bonus, col, col2, col3, wield_info;
int is_setup;

void create()
{
    object myOb;
    string *files, myFile, *Ids, tmp, tmp2, colors;
    colors = ({"%^RED%^", "%^BLUE%^", "%^MAGENTA%^", "%^GREEN%^", "%^ORANGE%^","%^CYAN%^", "%^WHITE%^", "%^BOLD%^%^BLACK%^", "%^YELLOW%^"});
    ::create();
    files = get_dir(COM+"*.c") - ({"rake-garrett.c"});
    myFile = files[random(sizeof(files))];
    myOb = new(COM+myFile);
    if(!objectp(myOb)) return;

    if(!query_property("enchantment")) set_property("enchantment", 3);

    set_wc(1, myOb->query_wc());
    set_large_wc(1, myOb->query_large_wc());
    set_type(myOb->query_type());
    set_weapon_prof(myOb->query_weapon_prof());
    set_weapon_speed(myOb->query_weapon_speed());
    set_critical_threat_range(myOb->query_critical_threat_range());
    set_critical_hit_multiplier(myOb->query_criticial_hit_multiplier());
    set_damage_type(myOb->query_damage_type());
    set_size(myOb->query_size());
    set_cointype("gold");
    set_value(2000);
    if(!is_setup) set_weight(myOb->query_weight());
    Ids = myOb->query_id();
    switch(random(4))
    {
         case 0:
              dam_bonus = "fire";
              tmp = "fiery";
              break;
         case 1:
              dam_bonus = "electricity";
              tmp = "crackling";
              break;
         case 2:
              dam_bonus = "cold";
              tmp = "freezing";
              break;
         case 3:
              dam_bonus = "acid";
              tmp = "acidic";
              break;
    }
    switch(random(4))
    {
         case 0:
              item_bonus = "fire resistance";
              tmp2 = item_bonus;
              wield_info = "roaraing aura of flame";
              break;
         case 1:
              item_bonus = "electricity resistance";
              tmp2 = "shocking resistance";
              wield_info = "crackling aura of electricity";
              break;
         case 2:
              item_bonus = "cold resistance";
              tmp2 = item_bonus;
              wield_info = "thick misty fog";
              break;
         case 3:
              item_bonus = "acid resistance";
              tmp2 = item_bonus;
              wield_info = "thick acidic fog";
              break;
     }
     col = colors[random(sizeof(colors))];
     if(!random(2)) col = "%^BOLD%^"+col;

     col2 = colors[random(sizeof(colors))];
     if(!random(2)) col2 = "%^BOLD%^"+col2;

     col3 = colors[random(sizeof(colors))];
     if(!random(2)) col3 = "%^BOLD%^"+col3;
     Ids += ({tmp + " "+myOb->query_name(), tmp + " weapon"});
     set_id(Ids);

     set_obvious_short(col+tmp + " " +myOb->query_name()+"%^RESET%^");
     set_short(col+tmp + " " +myOb->query_name() + " of %^RESET%^"+col2+tmp2+"%^RESET%^");
     set_item_bonus(item_bonus, 5+random(6));
     myOb->remove();
     set_long(col+"This weapon is the work of an %^RESET%^"+col2+"excellent%^RESET%^"+
     col+" craftsman. It is created from a dark gray substance that has been "+
     "enchanted by a potent magic that gives off a powerful %^RESET%^"+col3+tmp+
     " aura%^RESET%^"+col+". Strange magical %^BOLD%^%^CYAN%^symbols%^RESET%^"+col+
     " have been inscribed all over the visible surface of it that seem to be "+
     "moving about %^RESET%^"+col3+"chaotically%^RESET%^"+col+" on their own, without "+
     "any apparent reason.%^RESET%^");

     set_lore("%^RESET%^"+col2+"This weapon was one of many that has been unearthed "+
     "in the charu caverns. The magic that was used to forge it is rumored to be "+
     "highly volatile and somehow related to the caverns themselves. "+
     "It is possible that whatever magic was involved with forming the "+
     "creatures inside that place also had a hand in changing this weapon "+
     "into what it currently is.%^RESET%^");

     set_wield((:TO,"wield_func":));
     set_unwield((:TO,"unwield_func":));
     set_hit((:TO,"hit_func":));
     is_setup = 1;
}

int wield_func()
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    tell_object(ETO, "%^RESET%^"+col3+"You grasp "+TO->query_short()+"%^RESET%^"+
    col3+" and feel a %^RESET%^"+col2+wield_info+"%^RESET%^"+col3+" envelope you for a brief "+
    "moment, protecting you!%^RESET%^");

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^RESET%^"+col3+" grasps "+TO->query_short()+"%^RESET%^"+
        col3+" and is enveloped by a %^RESET%^"+col2+wield_info+"%^RESET%^"+col3+" for a brief "+
        "moment!%^RESET%^", ETO);
    }
    return 1;
}

int unwield_func()
{
    tell_object(ETO, "%^RESET%^"+col3+"You release your hold on "+TO->query_short()+
    "%^RESET%^"+col3+" and feel the protection granted by the %^RESET%^"+col2+wield_info+"%^RESET%^"+col3+
    " leave you!%^RESET%^");

    if(!ETO->query_invis())
    {
        tell_room(ETO, ETOQCN+"%^RESET%^"+col3+" releases "+ETO->QP+" hold on "+TO->query_short()+
        "%^RESET%^"+col3+" and seems more vulnerable!%^RESET%^", ETO);
    }
    return 1;
}

int hit_func(object targ)
{
    object myOb;
    if(random(200) < 120) return 0;
    myOb = new(CROB+"crater_specials");
    myOb->special_attack(TO, targ, dam_bonus);
    return 1;
}
