// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/camera_server/camera_server.proto)

#include "camera_server/camera_server.grpc.pb.h"
#include "plugins/camera_server/camera_server.h"

#include "mavsdk.h"

#include "lazy_server_plugin.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<
    typename CameraServer = CameraServer,
    typename LazyServerPlugin = LazyServerPlugin<CameraServer>>

class CameraServerServiceImpl final : public rpc::camera_server::CameraServerService::Service {
public:
    CameraServerServiceImpl(LazyServerPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::CameraServer::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_camera_server_result = new rpc::camera_server::CameraServerResult();
        rpc_camera_server_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_camera_server_result->set_result_str(ss.str());

        response->set_allocated_camera_server_result(rpc_camera_server_result);
    }

    static rpc::camera_server::TakePhotoFeedback translateToRpcTakePhotoFeedback(
        const mavsdk::CameraServer::TakePhotoFeedback& take_photo_feedback)
    {
        switch (take_photo_feedback) {
            default:
                LogErr() << "Unknown take_photo_feedback enum value: "
                         << static_cast<int>(take_photo_feedback);
            // FALLTHROUGH
            case mavsdk::CameraServer::TakePhotoFeedback::Unknown:
                return rpc::camera_server::TAKE_PHOTO_FEEDBACK_UNKNOWN;
            case mavsdk::CameraServer::TakePhotoFeedback::Ok:
                return rpc::camera_server::TAKE_PHOTO_FEEDBACK_OK;
            case mavsdk::CameraServer::TakePhotoFeedback::Busy:
                return rpc::camera_server::TAKE_PHOTO_FEEDBACK_BUSY;
            case mavsdk::CameraServer::TakePhotoFeedback::Failed:
                return rpc::camera_server::TAKE_PHOTO_FEEDBACK_FAILED;
        }
    }

    static mavsdk::CameraServer::TakePhotoFeedback translateFromRpcTakePhotoFeedback(
        const rpc::camera_server::TakePhotoFeedback take_photo_feedback)
    {
        switch (take_photo_feedback) {
            default:
                LogErr() << "Unknown take_photo_feedback enum value: "
                         << static_cast<int>(take_photo_feedback);
            // FALLTHROUGH
            case rpc::camera_server::TAKE_PHOTO_FEEDBACK_UNKNOWN:
                return mavsdk::CameraServer::TakePhotoFeedback::Unknown;
            case rpc::camera_server::TAKE_PHOTO_FEEDBACK_OK:
                return mavsdk::CameraServer::TakePhotoFeedback::Ok;
            case rpc::camera_server::TAKE_PHOTO_FEEDBACK_BUSY:
                return mavsdk::CameraServer::TakePhotoFeedback::Busy;
            case rpc::camera_server::TAKE_PHOTO_FEEDBACK_FAILED:
                return mavsdk::CameraServer::TakePhotoFeedback::Failed;
        }
    }

    static std::unique_ptr<rpc::camera_server::Information>
    translateToRpcInformation(const mavsdk::CameraServer::Information& information)
    {
        auto rpc_obj = std::make_unique<rpc::camera_server::Information>();

        rpc_obj->set_vendor_name(information.vendor_name);

        rpc_obj->set_model_name(information.model_name);

        rpc_obj->set_firmware_version(information.firmware_version);

        rpc_obj->set_focal_length_mm(information.focal_length_mm);

        rpc_obj->set_horizontal_sensor_size_mm(information.horizontal_sensor_size_mm);

        rpc_obj->set_vertical_sensor_size_mm(information.vertical_sensor_size_mm);

        rpc_obj->set_horizontal_resolution_px(information.horizontal_resolution_px);

        rpc_obj->set_vertical_resolution_px(information.vertical_resolution_px);

        rpc_obj->set_lens_id(information.lens_id);

        rpc_obj->set_definition_file_version(information.definition_file_version);

        rpc_obj->set_definition_file_uri(information.definition_file_uri);

        return rpc_obj;
    }

    static mavsdk::CameraServer::Information
    translateFromRpcInformation(const rpc::camera_server::Information& information)
    {
        mavsdk::CameraServer::Information obj;

        obj.vendor_name = information.vendor_name();

        obj.model_name = information.model_name();

        obj.firmware_version = information.firmware_version();

        obj.focal_length_mm = information.focal_length_mm();

        obj.horizontal_sensor_size_mm = information.horizontal_sensor_size_mm();

        obj.vertical_sensor_size_mm = information.vertical_sensor_size_mm();

        obj.horizontal_resolution_px = information.horizontal_resolution_px();

        obj.vertical_resolution_px = information.vertical_resolution_px();

        obj.lens_id = information.lens_id();

        obj.definition_file_version = information.definition_file_version();

        obj.definition_file_uri = information.definition_file_uri();

        return obj;
    }

    static std::unique_ptr<rpc::camera_server::Position>
    translateToRpcPosition(const mavsdk::CameraServer::Position& position)
    {
        auto rpc_obj = std::make_unique<rpc::camera_server::Position>();

        rpc_obj->set_latitude_deg(position.latitude_deg);

        rpc_obj->set_longitude_deg(position.longitude_deg);

        rpc_obj->set_absolute_altitude_m(position.absolute_altitude_m);

        rpc_obj->set_relative_altitude_m(position.relative_altitude_m);

        return rpc_obj;
    }

    static mavsdk::CameraServer::Position
    translateFromRpcPosition(const rpc::camera_server::Position& position)
    {
        mavsdk::CameraServer::Position obj;

        obj.latitude_deg = position.latitude_deg();

        obj.longitude_deg = position.longitude_deg();

        obj.absolute_altitude_m = position.absolute_altitude_m();

        obj.relative_altitude_m = position.relative_altitude_m();

        return obj;
    }

    static std::unique_ptr<rpc::camera_server::Quaternion>
    translateToRpcQuaternion(const mavsdk::CameraServer::Quaternion& quaternion)
    {
        auto rpc_obj = std::make_unique<rpc::camera_server::Quaternion>();

        rpc_obj->set_w(quaternion.w);

        rpc_obj->set_x(quaternion.x);

        rpc_obj->set_y(quaternion.y);

        rpc_obj->set_z(quaternion.z);

        return rpc_obj;
    }

    static mavsdk::CameraServer::Quaternion
    translateFromRpcQuaternion(const rpc::camera_server::Quaternion& quaternion)
    {
        mavsdk::CameraServer::Quaternion obj;

        obj.w = quaternion.w();

        obj.x = quaternion.x();

        obj.y = quaternion.y();

        obj.z = quaternion.z();

        return obj;
    }

    static std::unique_ptr<rpc::camera_server::CaptureInfo>
    translateToRpcCaptureInfo(const mavsdk::CameraServer::CaptureInfo& capture_info)
    {
        auto rpc_obj = std::make_unique<rpc::camera_server::CaptureInfo>();

        rpc_obj->set_allocated_position(translateToRpcPosition(capture_info.position).release());

        rpc_obj->set_allocated_attitude_quaternion(
            translateToRpcQuaternion(capture_info.attitude_quaternion).release());

        rpc_obj->set_time_utc_us(capture_info.time_utc_us);

        rpc_obj->set_is_success(capture_info.is_success);

        rpc_obj->set_index(capture_info.index);

        rpc_obj->set_file_url(capture_info.file_url);

        return rpc_obj;
    }

    static mavsdk::CameraServer::CaptureInfo
    translateFromRpcCaptureInfo(const rpc::camera_server::CaptureInfo& capture_info)
    {
        mavsdk::CameraServer::CaptureInfo obj;

        obj.position = translateFromRpcPosition(capture_info.position());

        obj.attitude_quaternion = translateFromRpcQuaternion(capture_info.attitude_quaternion());

        obj.time_utc_us = capture_info.time_utc_us();

        obj.is_success = capture_info.is_success();

        obj.index = capture_info.index();

        obj.file_url = capture_info.file_url();

        return obj;
    }

    static rpc::camera_server::CameraServerResult::Result
    translateToRpcResult(const mavsdk::CameraServer::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::CameraServer::Result::Unknown:
                return rpc::camera_server::CameraServerResult_Result_RESULT_UNKNOWN;
            case mavsdk::CameraServer::Result::Success:
                return rpc::camera_server::CameraServerResult_Result_RESULT_SUCCESS;
            case mavsdk::CameraServer::Result::InProgress:
                return rpc::camera_server::CameraServerResult_Result_RESULT_IN_PROGRESS;
            case mavsdk::CameraServer::Result::Busy:
                return rpc::camera_server::CameraServerResult_Result_RESULT_BUSY;
            case mavsdk::CameraServer::Result::Denied:
                return rpc::camera_server::CameraServerResult_Result_RESULT_DENIED;
            case mavsdk::CameraServer::Result::Error:
                return rpc::camera_server::CameraServerResult_Result_RESULT_ERROR;
            case mavsdk::CameraServer::Result::Timeout:
                return rpc::camera_server::CameraServerResult_Result_RESULT_TIMEOUT;
            case mavsdk::CameraServer::Result::WrongArgument:
                return rpc::camera_server::CameraServerResult_Result_RESULT_WRONG_ARGUMENT;
            case mavsdk::CameraServer::Result::NoSystem:
                return rpc::camera_server::CameraServerResult_Result_RESULT_NO_SYSTEM;
        }
    }

    static mavsdk::CameraServer::Result
    translateFromRpcResult(const rpc::camera_server::CameraServerResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::camera_server::CameraServerResult_Result_RESULT_UNKNOWN:
                return mavsdk::CameraServer::Result::Unknown;
            case rpc::camera_server::CameraServerResult_Result_RESULT_SUCCESS:
                return mavsdk::CameraServer::Result::Success;
            case rpc::camera_server::CameraServerResult_Result_RESULT_IN_PROGRESS:
                return mavsdk::CameraServer::Result::InProgress;
            case rpc::camera_server::CameraServerResult_Result_RESULT_BUSY:
                return mavsdk::CameraServer::Result::Busy;
            case rpc::camera_server::CameraServerResult_Result_RESULT_DENIED:
                return mavsdk::CameraServer::Result::Denied;
            case rpc::camera_server::CameraServerResult_Result_RESULT_ERROR:
                return mavsdk::CameraServer::Result::Error;
            case rpc::camera_server::CameraServerResult_Result_RESULT_TIMEOUT:
                return mavsdk::CameraServer::Result::Timeout;
            case rpc::camera_server::CameraServerResult_Result_RESULT_WRONG_ARGUMENT:
                return mavsdk::CameraServer::Result::WrongArgument;
            case rpc::camera_server::CameraServerResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::CameraServer::Result::NoSystem;
        }
    }

    grpc::Status SetInformation(
        grpc::ServerContext* /* context */,
        const rpc::camera_server::SetInformationRequest* request,
        rpc::camera_server::SetInformationResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                // For server plugins, this should never happen, they should always be
                // constructible.
                auto result = mavsdk::CameraServer::Result::Unknown;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "SetInformation sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->set_information(
            translateFromRpcInformation(request->information()));

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status SetInProgress(
        grpc::ServerContext* /* context */,
        const rpc::camera_server::SetInProgressRequest* request,
        rpc::camera_server::SetInProgressResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                // For server plugins, this should never happen, they should always be
                // constructible.
                auto result = mavsdk::CameraServer::Result::Unknown;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "SetInProgress sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->set_in_progress(request->in_progress());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status SubscribeTakePhoto(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::camera_server::SubscribeTakePhotoRequest* /* request */,
        grpc::ServerWriter<rpc::camera_server::TakePhotoResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        _lazy_plugin.maybe_plugin()->subscribe_take_photo(
            [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex](
                const int32_t take_photo) {
                rpc::camera_server::TakePhotoResponse rpc_response;

                rpc_response.set_index(take_photo);

                std::unique_lock<std::mutex> lock(*subscribe_mutex);
                if (!*is_finished && !writer->Write(rpc_response)) {
                    _lazy_plugin.maybe_plugin()->subscribe_take_photo(nullptr);

                    *is_finished = true;
                    unregister_stream_stop_promise(stream_closed_promise);
                    stream_closed_promise->set_value();
                }
            });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status RespondTakePhoto(
        grpc::ServerContext* /* context */,
        const rpc::camera_server::RespondTakePhotoRequest* request,
        rpc::camera_server::RespondTakePhotoResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                // For server plugins, this should never happen, they should always be
                // constructible.
                auto result = mavsdk::CameraServer::Result::Unknown;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "RespondTakePhoto sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->respond_take_photo(
            translateFromRpcTakePhotoFeedback(request->take_photo_feedback()),
            translateFromRpcCaptureInfo(request->capture_info()));

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyServerPlugin& _lazy_plugin;

    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk