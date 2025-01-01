// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Audio module"
// For conditions of distribution and use, see copyright notice in Export.hpp


namespace Nz
{
	inline AudioBuffer::AudioBuffer(std::shared_ptr<AudioDevice> device) :
	m_device(std::move(device))
	{
	}

	inline const std::shared_ptr<AudioDevice>& AudioBuffer::GetAudioDevice() const
	{
		return m_device;
	}
}
