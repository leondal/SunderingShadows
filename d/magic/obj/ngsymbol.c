// NG symbol for holy presence spell

#include <std.h>
#include <daemons.h>

inherit OBJECT;

int first;
object caster;

void create(){
    ::create();
    set_name("symbol");
    set_id(({"symbol","holy symbol","glowing symbol","image","ngsymbol"}));
    set_short("A %^BOLD%^glowing%^RESET%^ holy symbol");
    set_long("This is a brilliantly radiant image of a priest's holy symbol.");
    set_property("no animate",1);
    set_weight(1000);
    first = 1;
}

void init(){
    ::init();
    set_heart_beat(3);
}

void set_caster(object who){ caster = who;}

void heart_beat(){
    object *living,spell,*friends;
    int align,i,dam,level;
    
    if(!objectp(caster)) return;
    if(!objectp(ETO)) return;
    level = caster->query_guild_level("cleric");
    spell = query_property("spell");
    if(!objectp(spell)) return;
    tell_room(ETO,"%^BOLD%^The holy symbol glows brightly!");
    living = all_living(ETO);
    living = filter_array(living, "is_non_immortal",FILTERS_D);
    if(caster->query_party())
        friends=PARTY_D->query_party_members(caster->query_party());
    for(i=0;i<sizeof(living);i++){
        if(!objectp(living[i])) continue;
        if(sizeof(friends))
            if(member_array(living[i],friends) != -1) continue;
        align = living[i]->query_alignment();
        switch(align){
            case 3:
            case 9:
                tell_object(living[i],"%^BOLD%^%^RED%^The holy symbol %^YELLOW%^flashes%^RED%^ brightly as you look at it and you feel a shock.");
                dam = roll_dice(4,6) + level;
                spell->damage_targ(living[i],"torso",dam);
                break;
            case 2:
            case 6:
            case 8:
                if(first){
                    tell_object(living[i],"%^BOLD%^%^BLUE%^The holy symbol %^YELLOW%^flashes%^BLUE%^ brightly as you look at it and you feel a shock.");
                    dam = roll_dice(3,4) + level;
                    spell->damage_targ(living[i],"torso",dam);
                }
                break;
            case 1:
            case 5:
            case 7:
                if(first){
                    tell_object(living[i],"%^BOLD%^%^CYAN%^The holy symbol %^YELLOW%^flashes%^CYAN%^ brightly as you look at it and you feel a shock.");
                    dam = roll_dice(3,6);
                    spell->damage_targ(living[i],"torso",dam);
                }
                break;
            default:
                break;
        }
    }
    if(first) first = 0;
    return;
}
