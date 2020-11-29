#pragma once

#include "../Gorgo/Core.h"



namespace Gorgo {

	/// <summary>
	/// Class that represents a 4 coordinates float vector with default value equal to
	/// (0,0,0,1)
	/// </summary>
	class GRG_API Vector
	{
	public:
		Vector();
		Vector(float p_x, float p_y, float p_z);
		Vector(float p_x, float p_y, float p_z, float p_w);
		
		//Operations with numbers and vectors
		Vector operator*(int p_multNumber) const;
		Vector operator+(int p_sumNumber) const;
		Vector operator-(int p_subNumber) const;

		//Other operators
		GRG_API friend std::ostream& operator<<(std::ostream& p_os, const Gorgo::Vector& p_vector);

		/// <summary>
		/// Vector x,y,z,w coordinates with float precision
		/// </summary>
		float x;
		float y;
		float z;
		float w;
	};
}

