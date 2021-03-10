//

#include <std.h>
#define MAGIC_HITS ({0,1})
#define MAGIC_WIELDS ({0,1,2})

#define MAGIC_WEAR ({0,1,2})
#define MAGIC_STRUCK ({0,1})

int choose_hit(int prof){
    return MAGIC_HITS[random(sizeof(MAGIC_HITS))];
}
int choose_wield(int prof){
    return MAGIC_WIELDS[random(sizeof(MAGIC_WIELDS))];
}
int choose_wear(int prof){
    return MAGIC_WEAR[random(sizeof(MAGIC_WEAR))];
}
int choose_struck(int prof){
    return MAGIC_STRUCK[random(sizeof(MAGIC_STRUCK))];
}

int glow(object player){

    tell_room(ETP,"%^BOLD%^%^YELLOW%^"+PO->query_short()+"starts to glow.");
    return 1;
}

int unglow(object player){
    tell_room(ETP,"%^BOLD%^%^YELLOW%^"+PO->query_short()+"stops glowing.");
    return 1;
}

int magic_resistance(object player){
    player->set_property("magic resistance",20);
    tell_room(ETP,"%^CYAN%^"+player->query_cap_name()+" shivers slightly.",player);
    tell_object(player,"%^CYAN%^You shiver slightly.");
    return 1;
}


int unmagic_resistance(object player){
    player->set_property("magic resistance",-20);
    tell_room(ETP,"%^CYAN%^"+player->query_cap_name()+" shivers slightly.",player);
    tell_object(player,"%^CYAN%^You shiver slightly.");
    return 1;
}








int magic_wield(int which, object player){

    switch(which){
    case 1:
        return glow(player);
    case 2:
        return magic_resistance(player);
    default:
        return 1;
    }
}

int magic_unwield(int which, object player){

    switch(which){
    case 1:
        return unglow(player);
    case 2:
        return unmagic_resistance(player);
    default:
        return 1;
    }
}

int magic_hit(int which, object player, object target){

    switch(which){
    case 1:
        
    default:
        return 0;
    }
}


int magic_wear(int which, object player){

    switch(which){
    case 1:    
        return glow(player);
    case 2:
        return magic_resistance(player);
    default:
        return 1;
    }
}


int magic_remove(int which, object player){

    switch(which){
    case 1:    
        return unglow(player);
    case 2:
        return unmagic_resistance(player);
    default:
        return 1;
    }
}


int magic_struck(int which, object player, int dam, object what, object target){

    switch(which){
    case 1:    
    default:
        return 0;
    }
}

