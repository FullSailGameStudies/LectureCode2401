#pragma once
#include <string>
class Pickaxe
{
public:
	/// <summary>
	/// Swing will tell you what object you hit.
	/// </summary>
	/// <returns></returns>
	std::string Swing();//DECLARE the method

	//getters (accessors) provide access to the data
	std::string Label() { return label_; }

	//setters (mutators) allow you to modify the data
	void Label(std::string label) {
		if (label.size() > 0 && label != "Steev")
		{
			label_ = label;
		}
	}

private:
	std::string label_;//mLabel or _label

public:
};

