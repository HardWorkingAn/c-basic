#ifndef __POINT_TEMPLATE_H__
#define __POINT_TEMPLATE_H__

template<typename T>
class PointTemplate
{
private:
	T xpos, ypos;
public:
	PointTemplate(T x = 0, T y = 0);
	void ShowPosition() const;
};

#endif // !__POINT_TEMPLATE_H__




