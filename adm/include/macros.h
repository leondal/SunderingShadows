//

#define NAME(name,code) replace_string(code,"~NAME~",name);
#define ID(id,code) replace_string(code, "~ID~",identify(id));
#define SHORT(sh,code) replace_string(code,"~SHORT~",sh);
#define LONG(l,code) replace_string(code,"~LONG~",l);
#define WEIGHT(w,code) replace_string(code,"~WEIGHT~",w);
#define VALUE(v,code) replace_string(code,"~VALUE~",v);
#define AC(ac,code) replace_string(code,"~AC~",ac);
#define TYPE(t,code) replace_string(code,"~TYPE~",t);
#define LIMBS(l,code) replace_string(code,"~LIMBS~",identify(l));

#define REPLACE(l,code,s) replace_string(code,s,identify(l))
