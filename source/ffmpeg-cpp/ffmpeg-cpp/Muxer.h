#pragma once

#include "ffmpeg.h"
#include "std.h"

#include "StreamConfig.h"
#include "OutputStream.h"

namespace ffmpegcpp {

	class Muxer
	{
	public:

		Muxer(const char* fileName, std::vector<OutputStream*> streams);

		void WriteFrame(const AVRational *time_base, AVStream *stream, AVPacket *pkt);

		OutputStream* GetStream(int idx);

		void Close();

	private:

		void Open();

		std::vector<OutputStream*> streams;

		AVFormatContext* containerContext;
		AVOutputFormat* containerFormat;

		std::string fileName;
	};
}