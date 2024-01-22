#pragma once
#include <string>

enum ToolMaterial
{
	Wood, Stone, Gold, Iron, Diamond
};
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

	ToolMaterial Material() { return material_; }

	//ctor (constructor)
	//Pickaxe(); //default (no parameters)
	Pickaxe(ToolMaterial material, std::string label);
	Pickaxe(ToolMaterial material);

private:
	ToolMaterial material_;
	std::string label_;//mLabel or _label

public:
};

