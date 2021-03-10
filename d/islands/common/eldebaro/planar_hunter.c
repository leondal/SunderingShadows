#include <std.h>

inherit MONSTER;

int drink_kit;
object hunted, connected_to;

void create() 
{
    object ob;
    ::create();
}

void hunting(object targ)
{
    int lev, x, weaps;
    string *classes, *ids;
    object *inv, ob;
    if(!objectp(targ)) 
    {
        TO->remove();
        return;
    }
    hunted = targ;
    classes = (string *)targ->query_classes();
    lev = (int)targ->query_adjusted_character_level(); // Used for EXP
    
    set_name("a tall hooded figure");
    set_id( ({ "a tall hooded figure", "figure", "planar being", "being", "hunter", "hooded figure"}) );
    
    set_race("planar being");
    set_gender("male");
    
    
    set_short("%^BOLD%^%^BLACK%^A tall h%^BOLD%^%^WHITE%^oo%^BOLD%^%^BLACK%^ded f%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
    "gure (%^BOLD%^%^CYAN%^HOVERING %^BOLD%^%^BLACK%^and %^BOLD%^%^RED%^ENRAGED%^BOLD%^%^BLACK%^)%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This massive hooded creature "+
    "towers nearly twelve feet in the air. You have never before seen "+
    "anything quite like it. It looks translucent or nearly transparent, as "+
    "you can see through it fairly clearly and light passes through it with ease. "+
    "It glares at you when you glance at it and it's %^BOLD%^%^RED%^fiery red"+
    "%^BOLD%^%^BLACK%^ eyes appear full of purpose... a purpose that borders "+
    "or perhaps passes over into, obsession. You hope that you are not the object of "+
    "the obsession. It has two appendages that seem to function as arms jutting out "+
    "crazily from beneath the robe, though it has nothing that could be considered "+
    "legs as it just hovers in the air and actually blows about, as if an unfelt "+
    "breeze is constantly and chaotically pelting it.%^RESET%^");

    set_body_type("human");
    
    set_new_exp(lev, "high");    
    set_property("no death",1);
    set_property("full attacks",1);
    set_overall_ac((int)targ->query_ac());
    set_property("no paralyze",1);
    set_property("full attacks", 1);
    set_property("magic resistance", (int)targ->query_property("magic resistance"));
    set_property("attack bonus", (int)targ->query_property("attack bonus"));
    set_property("damage bonus", (int)targ->query_property("damage bonus"));
    set_property("damage resistance", (int)targ->query_property("damage resistance"));
    set_stats("strength",(int)targ->query_stats("strength"));
    set_stats("intelligence",(int)targ->query_stats("intelligence"));
    set_stats("wisdom",(int)targ->query_stats("wisdom"));
    set_stats("dexterity",(int)targ->query_stats("dexterity"));
    set_stats("charisma",(int)targ->query_stats("charisma"));
    set_stats("constitution",(int)targ->query_stats("constitution"));    
    set_spells(({"fireball", "lightning bolt", "magic missile", "cone of cold"}));
    set_spell_chance(45);
    
    inv = all_inventory(targ);
    
    for(x = 0;x < sizeof(classes);x++)
    {
        set_class(classes[x], (int)targ->query_class_level(classes[x]));
        continue;
    }
    for(x = 0;x < sizeof(inv);x++)
    {
        if(!objectp(inv[x])) continue;
        if(inv[x]->is_worn())
        {
            if(catch(ob = new(base_name(inv[x])))) continue;
            ob->move(TO);
            ob->set_property("monsterweapon", 1);
            command("wearall");
            if(!inv[x]->is_sheath()) continue;
        }
        if(inv[x]->is_weapon() && weaps < 2 || inv[x]->is_sheath())
        {
            if(inv[x]->is_sheath())
            {
                if(!sizeof(all_inventory(inv[x]))) continue;
                if(catch(ob = new(base_name(all_inventory(inv[x])[0])))) continue;              
            }
            else { if(catch(ob = new(base_name(inv[x])))) continue; }
            ob->move(TO);
            ob->set_property("monsterweapon", 1);
            ids = ob->query_id();
            command("wield "+ids[0]);
            weaps++;
            continue;
        }
        if((int)inv[x]->query_uses() && inv[x]->id("kit"))
        {
            if(catch(ob = new(base_name(inv[x])))) continue;
            ob->move(TO);
            ob->set_property("monsterweapon", 1);
            ob->set_uses((int)inv[x]->query_uses());
            drink_kit = 1;
            continue;
        }
        continue;
    }    
    set_monster_feats((string *)targ->query_player_feats());
    set_max_hp((int)targ->query_max_hp() * 8);
    set_hp(query_max_hp());    
    set_alignment((int)targ->query_alignment());    
    set_size(4);
    

    call_out("check_hunted", 20);
}

void connected_to(object ob)
{
    if(!objectp(ob)) return;
    connected_to = ob;
}

void die(object ob)
{
    if(objectp(connected_to)) connected_to->stop_hunting();
    ::die(ob);
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(sizeof(TO->query_attackers()))
    {
        if(drink_kit)
        {
            if((int)TO->query_hp() < ((int)TO->query_max_hp() / 2))
            {
                command("drink vial");
                command("drink vial");
                command("drink vial");
            }
        }
    }
}

void check_hunted()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(random(3)) 
    {
        call_out("check_hunted", roll_dice(2,10));
        return;
    }
    if(!objectp(hunted))
    {
        if(objectp(ETO)) tell_room(ETO, query_short()+"%^BOLD%^%^WHITE%^ simply fades away......%^RESET%^");
        TO->remove();
        return;
    }
    if(hunted->query_ghost())
    {
        if(objectp(ETO)) tell_room(ETO, query_short()+"%^BOLD%^%^WHITE%^ simply fades away......%^RESET%^");
        TO->remove();
        return;
    }
    if(environment(hunted) != ETO)
    {
        force_me("tell "+hunted->query_true_name()+" I will be seeing YOU shortly......I HAVE NOT forgotten my PROMISE!");
        if(!random(2))
        {
            TO->move(environment(hunted));
            tell_room(ETO, query_short()+"%^BOLD%^%^WHITE%^ materializes here and turns his focus to "+hunted->QCN+"!", hunted);
            tell_object(hunted, query_short()+"%^BOLD%^%^WHITE%^ materializes here and turns his focus to you!%^RESET%^");
            force_me("kill "+hunted->query_true_name());
        }
    }
    if(objectp(TO)) call_out("check_hunted", roll_dice(2,10));
    return;
}
