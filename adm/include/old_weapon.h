void set_hit_func(object ob) { set_hit((: call_other, ob, "weapon_hit" :)); }

void set_wield_func(object ob) { set_wield((: call_other, ob, "extra_wield" :)); }

void set_wield_string(string str) { set_wield(str); }

