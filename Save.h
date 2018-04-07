#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <fstream>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/nvp.hpp>

namespace nasic
{

	class opstruct
	{
	public:
		opstruct();
		~opstruct();
		bool saveOptions(nasic::opstruct& op, const char * filename);
		bool loadOptions(nasic::opstruct& op, const char * filename);

		int m_volume;
		int m_effects;
		int m_difficulty;

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & BOOST_SERIALIZATION_NVP(m_volume);
			ar & BOOST_SERIALIZATION_NVP(m_effects);
			ar & BOOST_SERIALIZATION_NVP(m_difficulty);
		}
	};

}
#endif
