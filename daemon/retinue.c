//ACTIVELY USED

#include <std.h>
#include <daemons.h>
#define CLASSES ({"fighter","thief","mage","cleric","monk"})
inherit DAEMON;

void init_knights(object player){
    string tobe, name, diety;
    int count, i, level, influence;
    mapping retainers, info;
    string *names;

    if(!FEATS_D->usable_feat(player,"leadership")) return 0;
    influence = (int)player->query_skill("influence");
    count = (influence/5) -1; //gaining followers from influence 10 upwards

    if ((int)player->get_retinue_level() >= influence && (int)player->query("retainer age") + 172800 > (int)player->query_age()) return; //reduced to 2 days pt for lost follower, down from 5

    retainers = player->get_retinue_mapping();
    if (retainers) names = keys(retainers);
    else names = ({});

    for (i=0;i<sizeof(names);i++) {
        info = retainers[names[i]];
        player->set_retinue_follower(info["name"],info["class"], info["level"], info["race"]);
    }
    count -= sizeof(names);
    for (i=0;i<count;i++) {
        tobe = CLASSES[random(sizeof(CLASSES))];
        level = influence/2 + random(influence/2);
        player->set_retinue_follower("daemon/names"->getName(), tobe, level, (string)player->query_race());
    }

    player->set_retinue_level(influence);
    player->set("retainer age",player->query_age());
}