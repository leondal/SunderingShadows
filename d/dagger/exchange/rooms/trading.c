// Trading Floor  - Merchant Exchange - LoKi - 19-02-2008 ((trading.c)

#include <std.h>
#include "../exchange.h"


inherit ROOM;
#include "../prices.h"
object ob;

void init() {
    ::init();
    add_action("list", "list");
    add_action("buy", "buy");
    add_action("sell", "sell");
}


void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("The Trading Floor");
    set_property("light",3);
    set_short("%^RESET%^%^ORANGE%^The Trading Floor%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The trading floor is an immense room"+
", easily large enough to fit several hundred people comfortably. The "+
"walls are constructed of pure %^RESET%^%^BOLD%^%^WHITE%^white marble "+
"%^RESET%^%^ORANGE%^cut into giant blocks that have been fitted perfectly."+
" The ceiling is high and vaulted, the o%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^"+
"%^ORANGE%^k ra%^RESET%^%^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^ters large "+
"enough to serve as the keels of galleons. You can see the balcony high "+
"above you and several people leaning over with drinks in hands watching"+
" the action. Three large %^RESET%^%^BOLD%^%^BLACK%^wrought iron chandeliers"+
" %^RESET%^%^ORANGE%^filled with giant %^RESET%^%^YELLOW%^candles %^RESET%^"+
"%^ORANGE%^provide more then enough illumination. A giant sign dominates "+
"one wall, listing commodities. %^RESET%^");
    set_exits(([
        "up" : ROOMS"cafe",
        "south" : ROOMS"foyer",
    ]));
    set_items(([
        ({"sign"}) : "%^RESET%^%^ORANGE%^A giant sign dominates the western "+
"wall. It lists every commodity traded in the exchange. Two young boys "+
"run back and forth with chalk to write new prices as they change.\n\n "+
" You can %^RESET%^%^YELLOW%^list%^RESET%^%^ORANGE%^ to get the "+
"current prices, or choose to %^YELLOW%^buy %^RESET%^%^ORANGE%^or "+
"%^YELLOW%^sell%^RESET%^%^ORANGE%^ certificates.%^RESET%^",
        ({"walls"}) : "%^RESET%^%^BOLD%^Formed from giant blocks of white marble, "+
"the walls are tall, dominated by the giant board.%^RESET%^",
({"ceiling"}) : "%^RESET%^%^ORANGE%^The ceiling rises high above you, the "+
"rafters large enough to be keels of galleons.%^RESET%^",
({"balcony"}) : "%^RESET%^%^ORANGE%^A balcony overlooks the trading floor. "+
"People lean over with drinks in hand%^RESET%^",
({"chandeliers"}) : "%^BLACK%^%^BOLD%^three chandeliers hang from the ceiling, "+
"providing light through %^RESET%^%^ORANGE%^numerous candles%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^You smell grease pencils.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^The whole area is filled with the "+
"urgent cries of a hundred traders.%^RESET%^");

}

void reset() {
  object ob;
  ::reset();
  if (!objectp(present(getuid(TO)+"_board"))) {
     ob = new("std/bboard");
     ob->set_name(getuid(TO)+"board");
     ob->set_id( ({ "board", getuid(TO)+"_board", "my board" }) );
     ob->set_board_id(geteuid(TO)+"_board");
     ob->set("short", "A small notice board");
     ob->set("long", "This is a small board with a collection of posts by the merchants, the Dragoons, and the owners of the Merchant Exchange concerning events that have effected prices or may effect pricesw\n");
     ob->set_max_posts(30);
     ob->set_restricted_post();
     ob->set_location(base_name(TO));
     ob->move(TO);
     ob->set_property("no steal",1);


  }
}
int list(){
       tell_object(TP,"%^BLACK%^%^BOLD%^You look over the current prices of commodities\n%^RESET%^");
       tell_object(TP,"%^WHITE%^Commodity                     %^WHITE%^Current Price Per Lot%^RESET%^\n");
       tell_object(TP,"%^YELLOW%^Lumber (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Lumber from Verbobone            %^RED%^"+Lumber_Verbobone+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Lumber from Tharis               %^RED%^"+Lumber_Tharis+"%^RESET%^");


       tell_object(TP,"\n%^YELLOW%^Cut Stone (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Stone from Antioch               %^RED%^"+Stone_Antioch+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Stone from Asgard                %^RED%^"+Stone_Asgard+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Furs and Hides (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Furs from Verbobone              %^RED%^"+Fur_Verbobone+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Furs from Tharis                 %^RED%^"+Fur_Tharis+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Furs from Asgard                 %^RED%^"+Fur_Asgard+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Textiles (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Textiles from Tabor              %^RED%^"+Textiles_Tabor+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Textiles from Antioch            %^RED%^"+Textiles_Antioch+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Food (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Food from Tabor                  %^RED%^"+Food_Tabor+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Food from Shadow                 %^RED%^"+Food_Shadow+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Food from Torm                   %^RED%^"+Food_Torm+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Unrefined Ore (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Ore from Kinaro                  %^RED%^"+Ore_Kinaro+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Ore from Asgard                  %^RED%^"+Ore_Asgard+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Weapons and Armor (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Armaments from Torm              %^RED%^"+Arm_Torm+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Armaments from Tonovi            %^RED%^"+Arm_Tonovi+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Armaments from Kinaro            %^RED%^"+Arm_Kinaro+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Natural Oils (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Oil from Torm                    %^RED%^"+Oil_Torm+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Oil from Graez                   %^RED%^"+Oil_Graez+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Spices (Per Standard Wagon Load) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Spices from Azha                 %^RED%^"+Spice_Azha+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Spices from Asgard               %^RED%^"+Spice_Seneca+"%^RESET%^");

       tell_object(TP,"\n%^YELLOW%^Slaves (Per 10) %^RESET%^");
       tell_object(TP,"%^ORANGE%^Elven Slaves from Tonovi         %^RED%^"+Slaves_Tonovi+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Un-trained Slaves from Juran     %^RED%^"+Slaves_Juran+"%^RESET%^");
       tell_object(TP,"%^ORANGE%^Indentured Criminals from Tharis %^RED%^"+Slaves_Tharis+"%^RESET%^");
return 1;


}

int buy(string str){
string type_asked,type,x;
int quantity_asked,total;
    if(!str) {
       tell_object(TP, "Try: 'buy <number> of <what>' (example %^YELLOW%^buy 10 of lumber from tharis%^RESET%^). ");
       return 1;
    }
    if(sscanf(str, "%d of %s", quantity_asked, type_asked)<2){
       tell_object(TP, "Try: 'buy <number> of <what>' (example %^YELLOW%^buy 10 of lumber from tharis%^RESET%^). ");
       return 1;
    }
    sscanf(str, "%d of %s", quantity_asked, type_asked);
        switch(type_asked){
            case "lumber from tharis":
               type = "Lumber_Tharis";
               total = quantity_asked*Lumber_Tharis;
            break;

            case "stone from antioch":
               type = "Stone_Antioch";
               total = quantity_asked*Stone_Antioch;
            break;

            case "stone from asgard":
               type = "Stone_Asgard";
               total = quantity_asked*Stone_Asgard;
            break;

            case "fur from verbobone":
               type = "Fur_Verbobone";
               total = quantity_asked*Fur_Verbobone;
            break;

            case "Fur from tharis":
               type = "Fur_Tharis";
               total = quantity_asked*Fur_Tharis;
            break;

            case "fur from asgard":
               type = "Fur_Asgard";
               total = quantity_asked*Fur_Asgard;
            break;

            case "textiles from Tabor":
               type = "Textiles_Tabor";
               total = quantity_asked*Textiles_Tabor;
            break;

            case "textiles from antioch":
               type = "Textiles_Antioch";
               total = quantity_asked*Textiles_Antioch;
            break;

            case "food from tabor":
               type = "Food_Tabor";
               total = quantity_asked*Food_Tabor;
            break;

            case "food from shadow":
               type = "Food_Shadow";
               total = quantity_asked*Food_Shadow;
            break;

            case "food from torm":
               type = "Food_Torm";
               total = quantity_asked*Food_Torm;
            break;

            case "ore from kinaro":
               type = "Ore_Kinaro";
               total = quantity_asked*Ore_Kinaro;
            break;

            case "ore from asgard":
               type = "Ore_Asgard";
               total = quantity_asked*Ore_Asgard;
            break;

            case "armaments from torm":
               type = "Arm_Torm";
               total = quantity_asked*Arm_Torm;
            break;

            case "armaments from tonovi":
               type = "Arm_Tonovi";
               total = quantity_asked*Arm_Tonovi;
            break;

            case "armaments from kinaro":
               type = "Lumber_Tharis";
               total = quantity_asked*Arm_Kinaro;
            break;

            case "oil from torm":
               type = "Oil_Torm";
               total = quantity_asked*Oil_Torm;
            break;

            case "oil from graez":
               type = "Oil_Graez";
               total = quantity_asked*Oil_Graez;
            break;

            case "spices from azha":
               type = "Spice_Azha";
               total = quantity_asked*Spice_Azha;
            break;

            case "spices from seneca":
               type = "Spice_Seneca";
               total = quantity_asked*Spice_Seneca;
            break;

            case "slaves from tonovi":
               type = "Slaves_Tonovi";
               total = quantity_asked*Slaves_Tonovi;
            break;

            case "slaves from juran":
               type = "Slaves_Juran";
               total = quantity_asked*Slaves_Juran;
            break;

            case "slaves from tharis":
               type = "Slaves_Tharis";
               total = quantity_asked*Slaves_Tharis;
            break;

            default:
               tell_object(TP, "%^BLACK%^%^BOLD%^That doesnt"+
" seem to be a valid commodity%^RESET%^");
            return 1;
            break;
        }
    if (!TP->query_funds("gold",total)){
        tell_object(TP, "%^BLACK%^%^BOLD%^You dig through your posessions and can't find enough to pay for that%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up to buy, then looks embarassed.%^RESET%^",TP);
        return 1;
    }
    TP->use_funds("gold", total);
    ob = new(OBJ"certificate.c");
    ob->set_value(quantity_asked);
    ob->set_type(type, type_asked);
    ob->move(TP);
    tell_object(TP, "%^RESET%^%^ORANGE%^You look over the prices, and purchase a certificate from a clerk for "+total+".%^RESET%^");
    tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up to a clerk and purchases a certificate.%^RESET%^",TP);
    return 1;
}

int sell(string str){
string type;
int total,total2,total3,tax;
    if(!str) return 0;
    ob = present(str, TP);
    if (!objectp(ob) || !ob->id("certificate")){
        tell_object(TP, "%^RESET%^%^RED%^You can't sell that...%^RESET%^");
        return 1;
    }

    total = (int)ob->check_value();
    type = (string)ob->check_type();
        switch(type){
            case "Lumber_Tharis":
               total2 = total*Lumber_Tharis;
            break;

            case "Stone_Antioch":
               total2 = total*Stone_Antioch;
            break;

            case "Stone_Asgard":
               total2 = total*Stone_Asgard;
            break;

            case "Fur_Verbobone":
               total2 = total*Fur_Verbobone;
            break;

            case "Fur_Tharis":
               total2 = total*Fur_Tharis;
            break;

            case "Fur_Asgard":
               total2 = total*Fur_Asgard;
            break;

            case "Textiles_Tabor":
               total2 = total*Textiles_Tabor;
            break;

            case "Textiles_Antioch":
               total2 = total*Textiles_Antioch;
            break;

            case "Food_Tabor":
               total2 = total*Food_Tabor;
            break;

            case "Food_Shadow":
               total2 = total*Food_Shadow;
            break;

            case "Food_Torm":
               total2 = total*Food_Torm;
            break;

            case "Ore_Kinaro":
               total2 = total*Ore_Kinaro;
            break;

            case "Ore_Asgard":
               total2 = total*Ore_Asgard;
            break;

            case "Arm_Torm":
               total2 = total*Arm_Torm;
            break;

            case "Arm_Tonovi":
               total2 = total*Arm_Tonovi;
            break;

            case "Arm_Kinaro":
               total2 = total*Arm_Kinaro;
            break;

            case "Oil_Torm":
               total2 = total*Oil_Torm;
            break;

            case "Oil_Graez":
               total2 = total*Oil_Graez;
            break;

            case "Spice_Azha":
               total2 = total*Spice_Azha;
            break;

            case "Spice_Seneca":
               total2 = total*Spice_Seneca;
            break;

            case "Slaves_Tonovi":
               total2 = total*Slaves_Tonovi;
            break;

            case "Slaves_Juran":
               total2 = total*Slaves_Juran;
            break;

            case "Slaves_Tharis":
               total2 = total*Slaves_Tharis;
            break;

        }
    total3 = total2* 0.85;
    tell_object(TP, "%^YELLOW%^You hand over your certificate to the"+
" clerk and they hand back a sack of gold amounting to "+total3+".\n%^RESET%^");
    tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps"+
" up to a clerk and sells a certificate.%^RESET%^",TP);
    tell_object(TP, "%^RESET%^%^ORANGE%^The clerk files the certificate"+
" and speaks in a brisk voice %^RESET%^%^BOLD%^'There are the funds for"+
" the commodity, less our... operating fee.'\n%^RESET%^");

    TP->add_money("gold", total3);
    ob->remove();
    return 1;
}
