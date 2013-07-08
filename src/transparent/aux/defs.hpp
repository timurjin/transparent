#ifndef TRANSPARENT_AUX_DEFS_HPP_2347diq282837a78273467shj29dfhvghs
#define TRANSPARENT_AUX_DEFS_HPP_2347diq282837a78273467shj29dfhvghs

#define T_CLASS_B(ClassNameD) T_CLASS_TR_B(ClassNameD, transparent::aux::void_type)


#define T_CLASS_TR_B(ClassNameD,TraitsClassD) class ClassNameD { \
public:\
typedef ClassNameD this_type; \
typedef ::transparent::aux::transparent_object_tag object_is_transparent;\
typedef TraitsClassD traits_type;\



#define T_FIELDS_B \
typedef transparent::aux::void_type TraitsType; \
template <typename VT> void call_visitor(const VT& vt,transparent::aux::first_list_element*) const { }\
typedef struct first_holder_type__: public transparent::aux::list_item_holder <transparent::aux::first_list_element, this_type,

#define T_F(TypeD,NameD)  TypeD > {  } NameD##_; T_F_ALL(NameD)

#define T_F_ALL(NameD) \
mutable NameD##_ NameD##_holder; \
public:\
void NameD(const NameD##_::value_type& v){ NameD##_holder.set(v);} \
const NameD##_::value_type& NameD(void) const{ return NameD##_holder.value;} \
       NameD##_::value_type& NameD(void)      { return NameD##_holder.value;} \
template <typename VT> void call_visitor(const VT& vt,NameD##_*) const { NameD##_holder.call_visitor(*this,vt,#NameD); }\
typedef struct after_##NameD##__: public transparent::aux::list_item_holder <NameD##_, this_type,


#define T_FIELDS_E \
transparent::aux::void_type > { } last_holder_type; \
mutable last_holder_type fields_list;\

#define T_CLASS_E \
template <typename VT> void call_visitor(const VT& vt) const  { fields_list.call_visitor_first(*this,vt); }\
};




#endif


