// upgraded to be able to make non-skinned ones (eg/ from vendors). N, 6/15.
#include <std.h>
#include <daemons.h>
inherit MATERIAL;

int value, damaged, ac, tanned, size;

void create(){
    ::create();
    set_name("skin");
    set_id(({"skin"}));
    set_type("leather");
}

void copy_corpse(object corpse){
    set_short("The skin of "+article(corpse->query_race())+" "+corpse->query_race());
    set_long("The skin of "+corpse->query_original_short()+".");
    set_subtype(corpse->query_race());
    add_id(corpse->query_race()+" skin");
    value = corpse->query_level();
    ac = corpse->query_ac();
    set_weight((int)corpse->query_size()*(random(4)+1));
    size = corpse->query_size();
    damaged += corpse->query_missing();
    if(value == 0)  value = 1;
    set_quality_type(10-(damaged*10/value));
    set_uses(size*3-random(damaged));
}

void setup_tanned_skin(string subtype){
    set_short("The skin of "+article(subtype)+" "+subtype);
    set_long("The skin of "+article(subtype)+" "+subtype+".");
    set_subtype(subtype);
    add_id(subtype+" skin");
    ac = 0;
    set_weight(5);
    size = 2;
    damaged = 0;
    set_uses(3+random(7));
    value = (query_uses()*50)+random(24);
    if(value == 0) value = 1;
    set_quality_type(10);
    tanned = 1;
}

void setup_feathers(string subtype){
    set_short("The feathers of "+article(subtype)+" "+subtype);
    set_long("The feathers of "+article(subtype)+" "+subtype+".");
    set_subtype(subtype);
    add_id(subtype+" feathers");
    add_id("feathers");
    ac = 0;
    set_weight(5);
    size = 2;
    damaged = 0;
    set_uses(3+random(7));
    value = (query_uses()*50)+random(24);
    if(value == 0) value = 1;
    set_quality_type(10);
}

string query_long(string str){
    string hold;
    hold = ::query_long(str);
    switch ((damaged*100/value)) {
    case 0:
        hold += " It is in perfect condition.";
        break;
    case 1..40:
        hold += " It has had some minor damage.";
    case 41..60:
        hold += " It has some holes and more serious damage.";
        break;
    case 61..75:
        hold += " It has serious damage and little solid space.";
        break;
    case 76..90:
        hold += " It has been mangled and has little undamaged surface.";
        break;
    default :
        hold += " It has little value remaining.";
    }
    if (tanned) {
        hold += "\nIt has been tanned and is ready for use.";
    }
    return hold;
}

void set_tanned(){ tanned = 1; }
int query_tanned(){ return tanned; }

int check_progress(int prof, object corpse){
    int rand = random(value);
    if (rand < prof) {
        corpse->set_skinned((int)corpse->query_skinned()+random(prof-rand)+1);
        if ((int)corpse->query_skinned() > (value*size)) {
            corpse->set_skinned(-1);
            return -1;
        }
        else return 0;
    }
    else {
        damaged += random(rand-prof)+1;
        if ((rand-prof) < value/2) {
            corpse->set_skinned((int)corpse->query_skinned()+1);
            if ((int)corpse->query_skinned() > (value*size)) {
                corpse->set_skinned(-1);
                return -1;
            }
        }
        return 1;
    }
}