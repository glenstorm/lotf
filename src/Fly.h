#ifndef _FLY_H_GUARD_
#define _FLY_H_GUARD_

#include <QObject>

typedef std::pair<int, int> Point;

class Fly : public QObject
{
	Q_OBJECT
private:
	unsigned int num_;
	/// Возраст
	unsigned int age_;
	/// Жива ли
	bool isAlive_;
	/// Скорость мухи
	double speed_;
	/// Пробег
	double track_;
	/// Текущие координаты мухи.
	Point position_;
public:
	Fly();

	Fly(unsigned int num, const Point& start_point);

	unsigned int age() const;
	void age(unsigned int);

	bool isAlive() const;
	void isAlive(bool);

	double speed() const;
	void speed(const double&);

	double track() const;
	void track(const double&);

	Point position() const;
	void position(const Point&);

public slots:
	void process(); 	/*  запускает полет мухи */
	void stop();    	/*  останавливает полет мухи */

signals:
	void changePos(); 	/* сигнал о изменении позиции */
	void finished(); 	/* сигнал о завершении */
};

#endif
	// _FLY_H_GUARD_
