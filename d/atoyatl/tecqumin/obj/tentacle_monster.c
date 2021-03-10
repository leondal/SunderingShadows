//Coded by Lujke

#include <std.h>
#include <daemons.h>
inherit OBJECT;

int clinging, feed;
void random_attach();

void create()
{
    ::create();
    set_name("tentacle monster");
    set_id(({ "tentacled monster", "small tentacled monster", "monster",
              "squid monster", "squidlike monster", "squid", "small tentacled"
              + " squidlike monster", "tentacled squidlike monster" }));
    set_short((: TO, "short_desc" :));
    set_weight(1);
    set_long((: TO, "long_desc" :));
    clinging = 0;
    feed = 0;
    set_heart_beat(1);
    set_property("no offer", 1);
}

void init()
{
    ::init();
    add_action("tear_me", "tear");
}

void heart_beat()
{
    if (objectp(ETO)) {
        if (!living(ETO)) {
            if (random(8) < 1) {
                random_attach();
            }
        } else {
            if (clinging > 0) {
                if (random(6) < 1) {
                    feed();
                }
            } else {
                if (random(6) < 1) {
                    cling(ETO);
                }
            }
        }
    }
}

int tear_me(string str)
{
    int roll, stren;
    if (!objectp(ETO) || !objectp(EETO) || !living(ETO)) {
        return -1;
    }
    stren = (int)ETO->query_stats("strength");
    roll = stren / (random(5) + 1) * 2;
    tell_room(EETO, ETO + " %^BOLD%^%^RED%^tears%^RESET%^ at "
              + ETO->QP + " face, trying to dislodge the %^MAGENTA%^sq"
              + "%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^i%^MAGENTA%^dl%^CYAN%^i"
              + "%^MAGENTA%^ke%^RESET%^ %^MAGENTA%^monster%^RESET%^!", TP);
    tell_object(TP, "You %^BOLD%^%^RED%^tear%^RESET%^ at your face,"
                + " trying to dislodge the %^MAGENTA%^sq%^BOLD%^%^BLUE%^u"
                + "%^RESET%^%^BLUE%^i%^MAGENTA%^dl%^CYAN%^i%^MAGENTA%^ke"
                + "%^RESET%^ %^MAGENTA%^monster%^RESET%^!");
    clinging -= roll;
    if (clinging < 1) {
        tell_room(EETO, TPQCN + " flings the %^MAGENTA%^sq"
                  + "%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^i%^MAGENTA%^dl%^CYAN%^i"
                  + "%^MAGENTA%^ke%^RESET%^ %^MAGENTA%^monster%^RESET%^ aside"
                  + " and staggers, gasping to catch " + TP->QP + "%^BOLD%^"
                  + " %^CYAN%^br%^WHITE%^ea%^CYAN%^th%^RESET%^!", TP);
        tell_object(TP, "You fling the %^MAGENTA%^sq"
                    + "%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^i%^MAGENTA%^dl%^CYAN%^i"
                    + "%^MAGENTA%^ke%^RESET%^ %^MAGENTA%^monster%^RESET%^ aside"
                    + " and stagger, gasping to catch your%^BOLD%^"
                    + " %^CYAN%^br%^WHITE%^ea%^CYAN%^th%^RESET%^!");
        TP->set_paralyzed(10, "You are catching your %^BOLD%^%^CYAN%^"
                          + " br%^WHITE%^ea%^CYAN%^th%^RESET%^!");
        clinging = 0;
        move(EETO);
    }
    return 1;
}

void random_attach()
{
    object* critters, players;
    int i, count;
    //tell_room(ETO, "Randomly attaching");
    critters = all_living(ETO);
    count = sizeof(critters);
    if (count < 1) {
        call_out("random_attach", 10);
        return;
    }
    players = ({});
    //tell_room(ETO, "Adding players");
    for (i = 0; i < count; i++) {
        if ((int)critters[i]->is_player()
            && !critters[i]->query_true_invis()) {
            tell_room(ETO, "Adding player " + critters[i]->query_name());
            players += ({ critters[i] });
        }
    }
    count = sizeof(players);
    if (count < 1) {
        return;
    }
    i = random(count);
    tell_room(ETO, "Clinging to " + players[i]->query_name());
    cling(players[i]);
}

string short_desc()
{
    string desc;
    desc = "%^RESET%^%^MAGENTA%^small %^BOLD%^%^BLACK%^tentacled"
           + " %^RESET%^%^MAGENTA%^sq%^BOLD%^%^CYAN%^u%^GREEN%^i%^RESET%^"
           + "%^MAGENTA%^dl%^BOLD%^%^BLUE%^i%^RESET%^%^MAGENTA%^ke"
           + " monster";
    if (clinging > 0 && living(ETO)) {
        if (TP == ETO) {
            desc += " - clinging to your %^BOLD%^%^BLUE%^face%^RESET%^!";
        } else {
            desc += " - clinging to " + ETO->QCN + "'s %^BOLD%^%^BLUE%^face"
                    + "%^RESET%^!";
        }
    }
    return desc;
}

string long_desc()
{
    string desc;
    desc = "This small creature is %^MAGENTA%^sq%^BOLD%^%^BLUE%^u"
           + "%^RESET%^%^BLUE%^i%^MAGENTA%^dl%^CYAN%^i%^MAGENTA%^ke%^RESET%^"
           + " in shape, with numerous %^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^"
           + "e%^BOLD%^%^BLACK%^nt%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^cles"
           + " %^RESET%^emerging from a central body. The %^BOLD%^%^BLACK%^t"
           + "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^MAGENTA%^a"
           + "%^BOLD%^%^BLACK%^cles%^RESET%^ writhe constantly when not"
           + " attached to something. The underside of the body is dominated"
           + " by a many toothed %^BOLD%^%^RED%^m%^RESET%^%^MAGENTA%^a%^BOLD%^"
           + "%^RED%^w%^RESET%^.";
    if (clinging > 0 && living(ETO)) {
        if (TP == ETO) {
            desc += " It is clinging to your %^BOLD%^%^BLUE%^face%^RESET%^,"
                    + " sucking out your %^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^i%^BOLD%^"
                    + "%^CYAN%^fe force%^RESET%^!"
                    + "                                                               "
                    + "You might want to %^BOLD%^%^WHITE%^<tear>%^RESET%^ it off.";
        } else {
            desc += " It is clinging to " + ETO->QCN + "'s %^BOLD%^%^BLUE%^"
                    + "face%^RESET%^!";
        }
    }
    switch (feed) {
    case 1:
        desc += " Its body looks somewhat %^BOLD%^%^BLUE%^swollen"
                + "%^RESET%^.";
        break;

    case 2:
        desc += " Its body is %^BOLD%^%^BLUE%^engorged%^RESET%^ and"
                + " %^GREEN%^bl%^BOLD%^%^GREEN%^oa%^RESET%^%^GREEN%^t%^BOLD%^"
                + "%^GREEN%^e%^RESET%^%^GREEN%^d%^RESET%^ from %^BOLD%^%^CYAN%^"
                + "f%^RESET%^%^CYAN%^ee%^BOLD%^%^CYAN%^d%^RESET%^%^CYAN%^i"
                + "%^BOLD%^%^CYAN%^ng%^RESET%^";
        break;

    case 3:
        desc += " Its %^BOLD%^%^BLUE%^engorged%^RESET%^ and %^GREEN%^bl"
                + "%^BOLD%^%^GREEN%^oa%^RESET%^%^GREEN%^t%^BOLD%^%^GREEN%^e"
                + "%^RESET%^%^GREEN%^d%^RESET%^ body %^BOLD%^%^RED%^thr%^RESET%^"
                + "%^RED%^o%^BOLD%^%^RED%^bs%^RESET%^ and %^BOLD%^%^BLUE%^str"
                + "%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^tch%^RESET%^%^BLUE%^e"
                + "%^BOLD%^%^BLUE%^s%^RESET%^, looking on the verge of%^BOLD%^"
                + " %^YELLOW%^ex%^RED%^pl%^YELLOW%^od%^RED%^i%^YELLOW%^ng"
                + "%^RESET%^";
        break;
    }
    return desc;
}

int cling(object clingee)
{
    clinging = 0;
    //tell_room(ETO, "Starting cling process");
    if (!objectp(clingee)
        || (!present(clingee, ETO) && !present(TO, clingee))
        || clingee->query_true_invis()) {
        return -1;
    }
    move(clingee);
    if (objectp(EETO)) {
        tell_room(EETO, query_short() + " flies up and attaches itself"
                  + " to " + clingee->QCN + "'s %^BOLD%^%^BLUE%^face%^RESET%^!"
                  , clingee);
    }
    tell_object(clingee, query_short() + " flies up and attaches itself"
                + " to your %^BOLD%^%^BLUE%^face%^RESET%^! It starts greedily"
                + " feeding on your %^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^i%^BOLD%^"
                + "%^CYAN%^fe force%^RESET%^!");
    clingee->set_paralyzed(50, "The %^MAGENTA%^sq%^BOLD%^%^BLUE%^u"
                           + "%^RESET%^%^BLUE%^i%^MAGENTA%^dl%^CYAN%^i%^MAGENTA%^ke%^RESET%^"
                           + " is clinging to your %^BOLD%^%^BLUE%^face%^RESET%^!"
                           + "                                                               "
                           + "You might want to %^BOLD%^%^WHITE%^<tear>%^RESET%^ it off.");
    clinging = 100;
}

int evade_splash(object splashtarg)
{
    object* worn;
    if (!FEATS_D->usable_feat(splashtarg, "evasion")) {
        return 0;
    }
    worn = splashtarg->all_armour();
    worn = distinct_array(worn);
    worn = filter_array(worn, "light_armor_filter", TO);
    if (sizeof(worn)) {
        return 0;             // wearing something too heavy!
    }
    tell_object(splashtarg, "You scramble for cover and avoid the"
                + " %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i%^BOLD%^d%^RESET%^"
                + "%^GREEN%^i%^BOLD%^c %^RESET%^%^GREEN%^m%^BOLD%^u%^RESET%^"
                + "%^GREEN%^cus%^RESET%^!");
    tell_room(EETO, "" + splashtarg->QCN + " scrambles for cover and"
              + " avoids the %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i%^BOLD%^"
              + "d%^RESET%^%^GREEN%^i%^BOLD%^c %^RESET%^%^GREEN%^m%^BOLD%^u"
              + "%^RESET%^%^GREEN%^cus%^RESET%^!", splashtarg);
    return 1;
}

void explode()
{
    object* critters;
    int i, count;
    if (!objectp(EETO)) {
        move("/d/shadowgate/void");
        return;
    }
    critters = all_living(EETO);
    count = sizeof(critters);
    if (count < 1) {
        return;
    }
    clinging = 0;
    tell_room(EETO, "%^BOLD%^%^BLUE%^The " + query_short() + " clinging to "
              + ETO->QCN + " %^BOLD%^%^BLUE%^ex"
              + "%^CYAN%^p%^BLUE%^l%^RED%^o%^BLUE%^d%^CYAN%^e%^BLUE%^s,"
              + " showering the room with %^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^i"
              + "%^BOLD%^%^GREEN%^le%^RESET%^, %^BOLD%^%^RED%^b%^RESET%^%^RED%^"
              + "u%^BOLD%^rn%^RESET%^%^RED%^i%^BOLD%^ng %^BOLD%^%^GREEN%^ac"
              + "%^RESET%^%^GREEN%^i%^BOLD%^d%^RESET%^%^GREEN%^i%^BOLD%^c"
              + " %^RESET%^%^GREEN%^m%^BOLD%^u%^RESET%^%^GREEN%^cus%^RESET%^!", ETO);
    tell_object(ETO, "%^BOLD%^%^BLUE%^The " + query_short() + " clinging to"
                + " you %^BOLD%^%^BLUE%^ex%^CYAN%^p%^BLUE%^l%^RED%^o%^BLUE%^d%^CYAN%^e"
                + "%^BLUE%^s, showering the room with %^BOLD%^%^GREEN%^v%^RESET%^"
                + "%^GREEN%^i%^BOLD%^%^GREEN%^le%^RESET%^, %^BOLD%^%^RED%^b%^RESET%^"
                + "%^RED%^u%^BOLD%^rn%^RESET%^%^RED%^i%^BOLD%^ng %^BOLD%^%^GREEN%^ac"
                + "%^RESET%^%^GREEN%^i%^BOLD%^d%^RESET%^%^GREEN%^i%^BOLD%^c"
                + " %^RESET%^%^GREEN%^m%^BOLD%^u%^RESET%^%^GREEN%^cus%^RESET%^!", ETO);
    for (i = 0; i < count; i++) {
        if (critters[i]->query_true_invis() || critters[i]->id("unfettered")) {
            continue;
        }
        if ("/daemon/saving_throw_d.c"->reflex_save(critters[i], 40)) {
            if (evade_splash(critters[i])) {
                tell_room(ETO, critters[i]->QCN + " %^BOLD%^%^CYAN%^%^dives out"
                          + " of the way of the  %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i"
                          + "%^BOLD%^d%^RESET%^%^GREEN%^i%^BOLD%^c %^RESET%^%^GREEN%^m"
                          + "%^BOLD%^u%^RESET%^%^GREEN%^cus%^RESET%^%^BOLD%^%^CYAN%^!"
                          , critters[i]);
                tell_object(critters[i], "%^ORANGE%^You dive out"
                            + " of the way of the  %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i"
                            + "%^BOLD%^d%^RESET%^%^GREEN%^i%^BOLD%^c %^RESET%^%^GREEN%^m"
                            + "%^BOLD%^u%^RESET%^%^GREEN%^cus%^ORANGE%^!");
                continue;
            }
        }
        tell_room(EETO, "%^GREEN%^" + critters[i]->QCN + "%^RESET%^%^GREEN%^ is"
                  + " drenched in %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i%^BOLD%^d"
                  + "%^RESET%^%^GREEN%^i%^BOLD%^c %^RESET%^%^GREEN%^m%^BOLD%^u"
                  + "%^RESET%^%^GREEN%^cus%^RESET%^!", critters[i]);
        tell_object(critters[i], "%^BOLD%^%^GREEN%^You are%^BLUE%^ drenched"
                    + "%^GREEN%^ in %^BOLD%^%^GREEN%^ac%^RESET%^%^GREEN%^i%^BOLD%^d"
                    + "%^RESET%^%^GREEN%^i%^BOLD%^c %^RESET%^%^GREEN%^m%^BOLD%^u"
                    + "%^RESET%^%^GREEN%^cus%^RESET%^!");
        critters[i]->cause_typed_damage(TO, critters[i]->return_target_limb(),
                                        300 + random(300), "acid");
//    tell_object(critters[i], "%^BOLD%^%^RED%^HP: " + critters[i]->query_hp()
//      +" " + critters[i]->query_hp()*100/critters[i]->query_max_hp() + "%");
    }
    move("/d/shadowgate/void");
}

void feed()
{
    string* classes, cl;
    mapping neglevs;
    int neglev;
    if (clinging < 1) {
        return;
    }
    if (!living(ETO)) {
        call_out("random_attach", 5);
        return;
    }
    if (feed > 2) {
        explode();
        return;
    }
    tell_object(ETO, "The %^BOLD%^%^BLACK%^tentacled"
                + " %^RESET%^%^MAGENTA%^sq%^BOLD%^%^CYAN%^u%^GREEN%^i%^RESET%^"
                + "%^MAGENTA%^dl%^BOLD%^%^BLUE%^i%^RESET%^%^MAGENTA%^ke"
                + " monster %^BOLD%^%^GREEN%^sucks %^RESET%^ out your %^BOLD%^"
                + "%^BLUE%^life%^RESET%^.");
    if (objectp(EETO)) {
        tell_room(EETO, "The %^BOLD%^%^BLACK%^tentacled"
                  + " %^RESET%^%^MAGENTA%^sq%^BOLD%^%^CYAN%^u%^GREEN%^i%^RESET%^"
                  + "%^MAGENTA%^dl%^BOLD%^%^BLUE%^i%^RESET%^%^MAGENTA%^ke"
                  + " monster%^RESET%^ attached to " + ETO->QCN + "'s face"
                  + " %^BOLD%^%^GREEN%^q%^RESET%^%^GREEN%^ui%^BOLD%^v%^RESET%^"
                  + "%^GREEN%^e%^BOLD%^rs%^RESET%^ and %^BOLD%^%^CYAN%^sh%^RESET%^"
                  + "%^CYAN%^u%^BOLD%^dd%^RESET%^%^CYAN%^e%^BOLD%^rs%^RESET%^ as"
                  + " it %^BOLD%^%^BLUE%^feeds%^RESET%^.", ETO);
    }
    ETO->set_paralyzed(50, "The %^MAGENTA%^sq%^BOLD%^%^BLUE%^u"
                       + "%^RESET%^%^BLUE%^i%^MAGENTA%^dl%^CYAN%^i%^MAGENTA%^ke%^RESET%^"
                       + " is clinging to your %^BOLD%^%^BLUE%^face%^RESET%^!"
                       + "                                                               "
                       + "You might want to %^BOLD%^%^WHITE%^<tear>%^RESET%^ it off.");
    classes = ETO->query_classes();
    if (sizeof(classes) < 1) {
        call_out("feed", 10);
        return;
    }
    cl = classes[random(sizeof(classes))];
    neglevs = ETO->query("negative level");
    if (sizeof(neglevs) > 0) {
        neglev = neglevs[cl];
    } else {
        neglev = 0;
    }
    //ETO->set("negative level", ([cl : neglev -2]));
    feed += 1;
    call_out("feed", 5);
}
