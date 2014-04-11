#define Item_Clothing   0
#define Item_Ammo       1
#define Item_Gun        2
#define Item_Blade      3
#define Item_Consumable 4
#define Item_Tool       5
#define Item_Components 6

class Item{
public:
	Item();
	Item(int Type);

private:
	char m_Symbol;
	int m_ItemType;
	int m_Weight;
	int m_Volume;
	int m_Bash;
};

Item::Item(){

}

Item::Item(int Type){

}