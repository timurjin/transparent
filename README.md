Transparent is c++ reflection mechanism
===
Usage:

Transparent could be used in IPC mechanisms to provide data seialization/deserialization for request/response 
transportation between servers and clients.

```
	T_CLASS_B(some_message)
		T_FIELDS_B
		   T_F(std::string, value)
		T_FIELDS_E
	T_CLASS_E


	some_message res;
	res.value("Some string value");

	cout << transparent::formats::json::write(res);
```
The output will be:
	
```
{
    "value" : "Some string value",
},
```

---
Transparent could be used to access nested objects in path-like manner:

```
        test::DemoClass demo;
	demo.inserted_elt().inserted_elt().long_value();                              // Compile time read access
	(path(demo) / "inserted_elt" / "inserted_elt" / "long_value").value<long>();  // Runtime read access analogue
	
	path(demo) / "inserted_elt" / "inserted_elt" / "long_value" = 42;            // Runtime object write
	demo.inserted_elt().inserted_elt().long_value(42);                            // Compile time object write
```	
	


---
The functionality of library built on a Visitor pattern. So any extension (for example sql or xml generation) can by written as a Visitor which solves desired tasks. 

```
// Let's write value 42 to any integer field, or value 24 to integer field with name "foo"
struct write_42_or_24_visitor
{
	template<typename T>
	void container_start(T& a, const char* name) const
	{
		// Will be called before first container element
		
	}

	template<typename T>
	void container_end(T& a, const char* name) const
	{
	   // Will be called after last container element
	}

	template<typename T>
	void complex_start(T& a, const char* name) const
	{
		   // Will be called before any complex element start 
		   // Complex elements is a nested class or struct instances defined via Transparent DSL
	
	}

	template<typename T>
	void complex_end(T& a, const char* name) const
	{
   	       // Will be called after any complex element end 
		   // Complex elements is a nested class or struct instances defined via Transparent DSL
	
	}

	template<typename T>
	void value(T& a, const char* name = 0) const
	{
	     // will be called for any other field in a object or it nested elements
	}

	void value(int& a, const char* name = 0) const
	{
	    // Will be called for any int field while interating throught objects hieararchy
		if(name!=0 && strcmp(name,"foo")==0)
		{
			a=24;
		}
		else
		{
			a = 42;
		}
	}
};


	test::DemoClass demo;                   // This is a object with some nested elements
	write_42_or_24_visitor v;               // This is our worker
	transparent::utils::iterate(demo, v);   // Let's walk deep throught nested objects
```
---

Transparent is based on a full serializable class definintion via Transparent DSL but not on a serializable fields demarcation. Thus, target code, will have less duplicates what probably will increase it's readability.

```
T_CLASS_B(some_message)
	T_FIELDS_B
	   T_F(std::string, value)
	T_FIELDS_E
T_CLASS_E
```

```
class some_message
{
public:
	std::strint value;

	SERIALIZE_B
	   FIELD(std::string, value)
	SERIALIZE_E
};
```

 




