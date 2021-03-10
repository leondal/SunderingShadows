#include <std.h>
#include <materials.h>


inherit OBJECT;

int _uses;
string _type;
string _subtype;
string _color = "";
string _quality = "";
int iQuality = 5;


void create(){
     ::create();
}

int is_material(){
    return 1;
}

void set_type(string type){
    if(member_array(type, MATERIAL_TYPES) == -1) error("Invalid material specified");
     _type = type;
}

string query_type(){
    if(!_type) error("No type specified.");
     return _type;
}
void set_subtype(string type){
    _subtype = type;
}

string query_subtype(){
    if(!_subtype) return _type;
     return _subtype;
}

void set_uses(int use){
      if(use < 0) use =0;
     _uses = use;
}

int query_uses(){
    return _uses;
}

int use(int i){
     if(!i) i = 1;
     _uses-=i;
     if (!_uses) {
         remove();
     }
     return _uses;
}

void set_color(string c){
    _color = c;
}

string query_color(){
    return _color;
}
void set_quality(string q){
     _quality = q;
}

string query_quality(){
     return _quality;
}

void set_quality_type(int q){
     q = q>10?10:q;
    iQuality = q;
    switch(q){
        case 1:
            set_quality("very poor quality");
            break;
        case 2:
          set_quality("poor quality");
          break;
        case 3:
            set_quality("well below average quality");
            break;
        case 4:
         set_quality("below average quality");
            break;
        case 5:
            set_quality("average quality");
            break;
        case 6:
            set_quality("above average quality");
            break;
        case 7:
            set_quality("well above average quality");
            break;
        case 8:
            set_quality("excellent quality");
            break;
        case 9:
            set_quality("very excellent quality");
            break;
         case 10:
            set_quality("highest quality");
            break;
        }
}

int query_quality_type(){
     return iQuality;
}

string query_long(string str){
   string hold;
   hold = ::query_long(str);
   hold += " It appears to have approximately "+query_uses()+" units left. If you have another material of the same type, you can <combine MATERIAL with MATERIAL2>.";

   return hold;
}

init(){
    ::init();
    if (query_uses() < 1) {
        TO->remove();
    }
    if(TP == ETO){
        add_action("combine","combine");
    }
}

int combine(string str){
    string th, that;
    object obj;
    if(!str){
        return notify_fail("Combine what with what?\n");
    }

    if(sscanf(str,"%s with %s",th, that) != 2){
        return notify_fail("Combine what with what?\n");
    }
    if (present(th,TP) != TO) {
        return notify_fail("Combine what with what?\n");
    }
    if (!(obj = present(that,TP))) {
        return notify_fail("Combine what with what?\n");
    }
    if(obj == TO) return notify_fail("You can't combine the same obj.\n");

    if (query_type() != (string)obj->query_type() || query_subtype() != (string)obj->query_subtype()) {
        return notify_fail("You can only combine the same type of materials\n");
    }

    _uses += (int)obj->query_uses();

    iQuality = iQuality<(int)obj->query_quality_type()?iQuality:(int)obj->query_quality_type();
    set_quality_type(iQuality);
    obj->remove();
    write("You combine the "+query_subtype()+" into one mass.");
    return 1;
}
