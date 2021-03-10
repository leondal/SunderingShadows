//herb inherit for new Seneca
//coded by ~Circe~ 4/19/08 
//with descriptions and actions by Lurue
// moved to /d/common for general brewing use. N, 12/11.
#include <std.h>
#include <brewing.h>
inherit OBJECT;

string herb_name;
void set_herb_name(string str);
void query_herb_name();

void create(){
    ::create();
    set_herb_name("blar");
    set_weight(1);
}

void init(){
   ::init();
   add_action("use_em","use");
}

int use_em(string str){
   if(!id(str)) return 0;
   switch(random(100)){
      case 0..74:   tell_object(TP,"You use the %^GREEN%^"+herb_name+" %^RESET%^and soon feel it affecting you in a helpful way.");
         tell_room(ETP,""+TPQCN+" uses some %^GREEN%^"+herb_name+"%^RESET%^.",TP);
         TO->remove();
         break;
      case 75..94:   tell_object(TP,"You use the %^GREEN%^"+herb_name+" %^RESET%^and wait, but feel no effect.");
         tell_room(ETP,""+TPQCN+" uses some %^GREEN%^"+herb_name+"%^RESET%^.",TP);
         TO->remove();
         break;
      default: tell_object(TP,"You use the %^GREEN%^"+herb_name+" %^RESET%^and soon begin to feel nauseous and ill!");
         tell_room(ETP,""+TPQCN+" uses some %^GREEN%^"+herb_name+"%^RESET%^.",TP);
         TO->remove();
         break;
   }
   return 1;
}

void set_herb_name(string str){
    string *herbs;
    mapping herb_map = ([]);

    herb_map = ([ 
        "alfalfa" : ([ "part" : "leaves", "type" : "in infusions or powder", "use" : "to help keep the heart healthy and the blood flowing evenly", "value" : 30 ]),
        "allspice" : ([ "part" : "seeds", "type" : "as an oil or infusion", "use" : "as a digestive aid or pain reliever", "value" : 35]),
        "aloe" : ([ "part" : "cut leaves", "type" : "directly on burns or scrapes", "use" : "to soothe pain and prevent infection", "value" : 25 ]),
        "anise" : ([ "part" : "seeds", "type" : "as an infusion or tincture", "use" : "to treat a cough or provide relief from cramping", "value" : 50 ]),
        "basil" : ([ "part" : "leaves", "type" : "as an infusion or tincture", "use" : "to treat intestinal illnesses and promote a healthy immune system", "value" : 30 ]),
        "bay" : ([ "part" : "fresh leaves", "type" : "as an infusion or tincture", "use" : "to soothe sore joins and treat infections as well as aid in relaxation", "value" : 55 ]),
        "caraway" : ([ "part" : "seeds", "type" : "eaten fresh or as an infusion or tincture", "use" : "to soothe the digestive tract by expelling gas and to aid in treating cramping", "value" : 60 ]),
        "catnip" : ([ "part" : "leaves and flowers", "type" : "as an infusion", "use" : "to relieve chest congestion and lessen phlegm", "value" : 20 ]),
        "chamomile" : ([ "part" : "flowers", "type" : "as an infusion", "use" : "to treat wounds and inflammations or as a sedative", "value" : 45 ]),
        "chicory" : ([ "part" : "fresh leaves", "type" : "as an infusion or tincture", "use" : "to cleanse and balance the urinary and digestive systems", "value" : 60 ]),
        "cinnamon" : ([ "part" : "bark", "type" : "crushed or powdered", "use" : "to help prevent infection and as a pain reliever when applied directly to the injury", "value" : 45 ]),
        "clove" : ([ "part" : "seeds", "type" : "as an oil or infusion", "use" : "to relieve toothaches or to help reduce fungal infections of the feet", "value" : 35 ]),
        "coriander" : ([ "part" : "seeds", "type" : "as an infusion", "use" : "to help calm intestinal ailments when taken internally or to soothe muscle and joint pain when applied externally", "value" : 65 ]),
        "dandelion" : ([ "part" : "fresh leaves", "type" : "as an infusion or tincture", "use" : "to help with weight loss and as a digestive aid", "value" : 15 ]),
        "dill" : ([ "part" : "seeds", "type" : "as an infusion or tincture", "use" : "to fight infection and soothe stomach pains", "value" : 25 ]),
        "eucalyptus" : ([ "part" : "leaves", "type" : "as an oil or tincture", "use" : "to loosen phlegm and ease chest pain while opening sinuses", "value" : 50 ]),
        "fennel" : ([ "part" : "seeds", "type" : "as an infusion or tincture", "use" : "to soothe stomach cramps", "value" : 40 ]),
        "feverfew" : ([ "part" : "leaves", "type" : "fresh or as a powder", "use" : "to help with headaches", "value" : 45 ]),
        "garlic" : ([ "part" : "cloves", "type" : "fresh or as an infusion or tincture", "use" : "as a cure all or a preventative", "value" : 25 ]),
        "ginger" : ([ "part" : "roots", "type" : "fresh or as an infusion or tincture", "use" : "to aid with morning sickness and other digestive symptoms as well as to help with arthritis and improve circulation", "value" : 55 ]),
        "ginkgo" : ([ "part" : "leaves", "type" : "fresh or as an infusion", "use" : "to help improve memory and aid ailments such as blindness or deafness", "value" : 60 ]),
        "ginseng" : ([ "part" : "mature roots", "type" : "as a powder", "use" : "to improve the body's resistances and boost the immune system", "value" : 35 ]),
        "horehound" : ([ "part" : "flowers", "type" : "as an infusion or tincture", "use" : "to act as a cough remedy and soothe chest pains", "value" : 30 ]),
        "juniper" : ([ "part" : "berries", "type" : "as an infusion", "use" : "to aid with arthritis and improve circulation", "value" : 40 ]),
        "kelp" : ([ "part" : "leaves", "type" : "as an infusion", "use" : "to fight infection when applied directly to a wound", "value" : 50 ]),
        "lavender" : ([ "part" : "flowers", "type" : "fresh", "use" : "usually in bath water to reduce stress and provide calm when inhaled", "value" : 30 ]),
        "marjoram" : ([ "part" : "flowers", "type" : "as a powder", "use" : "to aid with digestion by relieving the feeling of bloating", "value" : 25 ]),
        "mint" : ([ "part" : "leaves", "type" : "as an infusion, tincture, or powder", "use" : "to help combat infection and sterilize a wound or to ease sinus and chest congestion when inhaled.  When chewed, it can also help fight morning sickness", "value" : 25 ]),
        "myrrha" : ([ "part" : "leaves", "type" : "as a powder, infusion, or tincture", "use" : "to help fight bacteria in the mouth or gums", "value" : 45 ]),
        "nettle" : ([ "part" : "plant", "type" : "as an infusion or tincture", "use" : "to help prevent hay fever and allergies when taken regularly", "value" : 30 ]),
        "parsley" : ([ "part" : "leaves", "type" : "fresh, or as an infusion, tincture, or powder", "use" : "to help lower fever and cool the blood.  When chewed, it can also act as a breath freshener and fight allergies", "value" : 15 ]),
        "red pepper" : ([ "part" : "pepper", "type" : "fresh or as an infusion", "use" : "to help soothe chronic pain when applied externally or to help with headaches and aid digestion when taken internally", "value" : 35 ]),
        "rosemary" : ([ "part" : "leaves", "type" : "as a tea, infusion, or tincture", "use" : "to act as a decongestant as well as aid digestion", "value" : 40 ]),
        "saffron" : ([ "part" : "stigma of the flower", "type" : "to", "use" : "help with circulation and soothe the nerves", "value" : 60 ]),
        "sage" : ([ "part" : "leaves", "type" : "fresh, or as an infusion, tincture, or powder", "use" : "to fight infection, help preserve foods and drinks, and aid with sore throats", "value" : 45 ]),
        "savory" : ([ "part" : "leaves", "type" : "as an infusion", "use" : "to soothe and calm children when taken internally", "value" : 30 ]),
        "skullcap" : ([ "part" : "leaves", "type" : "as an infusion", "use" : "to act as a mild sedative and to aid with sleep", "value" : 40 ]),
        "tarragon" : ([ "part" : "leaves", "type" : "fresh", "use" : "to function as a mild anesthetic to prevent infections.  It can also help relieve toothaches when chewed", "value" : 35 ]),
        "tea" : ([ "part" : "leaves", "type" : "as an infusion", "use" : "to help with congestion, asthma, tooth decay, and to treat colds and other mild discomforts of illness", "value" : 15 ]),
        "thyme" : ([ "part" : "leaves", "type" : "fresh or as an infusion", "use" : "to help fight and prevent bacteria and disease as well as aid digestion and prevent cramping", "value" : 25 ]),
        "tobacco" : ([ "part" : "leaves", "type" : "dried, and then smoked or chewed", "use" : "as a strong stimulant, although it is known to have addictive qualities", "value" : 35 ]),
        "vanilla" : ([ "part" : "seeds", "type" : "as an infusion", "use" : "to aid with various stomach ailments. It is also highly prized for its flavor in cooking", "value" : 50 ]),
        "valerian" : ([ "part" : "roots", "type" : "as an infusion or tincture", "use" : "to act as a mild sedative or tranquilizer", "value" : 50 ]),
        "vervain" : ([ "part" : "plant", "type" : "as an infusion or tincture", "use" : "to act as a pain killer for aches, pains, and headaches", "value" : 40 ]),
        "witch hazel" : ([ "part" : "plant", "type" : "as an infusion or tincture", "use" : "to act as an antiseptic and to help soothe cuts, bruises, and sore muscles while relieving some of the pain", "value" : 35 ]),
        "yarrow" : ([ "part" : "leaves and flowers", "type" : "as an infusion or tincture", "use" : "to prevent infection in cuts and scrapes.  If taken internally, it can act as a mild sedative and relaxer", "value" : 45 ])
    ]);

    herbs = keys(herb_map);
    if(!str) herb_name = herbs[random(sizeof(herbs))];
    else herb_name = str;
    if(member_array(herb_name,herbs) == -1) herb_name = herbs[random(sizeof(herbs))];

    set_name("herb");
    set_id(({"herb","packet","packet of herbs",""+herb_name+"","packet of "+herb_name+""}));
    //set_short("%^RESET%^a small %^ORANGE%^paper packet %^RESET%^containing some %^GREEN%^"+herb_name+"%^RESET%^");
    // switched around the location of the name in the short desc because they were getting truncated in shop lists before a player could read the name of the herb.
    set_short("%^RESET%^some %^GREEN%^"+herb_name+"%^RESET%^ contained in a small %^ORANGE%^paper packet%^RESET%^");
    set_long("This is a small paper packet containing some "+herb_name+".  The "+herb_map[herb_name]["part"]+" of "+herb_name+" can be used "+herb_map[herb_name]["type"]+
" "+herb_map[herb_name]["use"]+".  You can <%^BOLD%^use "+herb_name+"%^RESET%^>.");
    set_value(herb_map[herb_name]["value"]);
    set_cointype("silver");
}

void query_herb_name(){ return herb_name; }

int is_herb(){ return 1; }