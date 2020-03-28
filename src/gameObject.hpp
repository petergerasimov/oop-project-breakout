#ifndef __GAME_OBJECT
#define __GAME_OBJECT

class GameObject
{
	private:
		float x;
		float y;
		void draw();
	public:
		GameObject();
		GameObject(float x, float y);
		~GameObject();
		//Setters
		void setX(float x);
		void setY(float y);
		void setXY(float x, float y);
		//Getters
		float getX();
		float getY();

		void update();
		//Maybe this should be an array of objects
		bool isColliding(GameObject& a);
};


#endif //__GAME_OBJECT