<center>

<h1>bot</h1>

[README主版本(English)](README.md)

</center>

`config.json`配置文件可选项：

- `address`：监听地址
- `port`：端口
- `token`：token（不填写即不检查token）

<!-- TREE_START -->
```
bot
├── LICENSE.txt
├── README.md
├── README_CN.md
├── bot
│   ├── ArgvCli.ixx
│   ├── Boot.ixx
│   ├── BotConfig.ixx
│   ├── Clean.ixx
│   ├── Cli.ixx
│   ├── ErrCode.ixx
│   ├── ErrCode.throwError.ixx
│   ├── FileOstream.ixx
│   ├── GetJson.ixx
│   ├── Lang.ixx
│   ├── LegalArg.ixx
│   ├── Log.ixx
│   ├── LogLevel.ixx
│   ├── Version.ixx
│   ├── Websocket.cpp
│   ├── Websocket.hpp
│   ├── Websocket.internal.ixx
│   ├── bot.cpp
│   ├── bot.vcxproj
│   ├── bot.vcxproj.filters
│   └── lang
│       ├── en.json
│       └── zh.json
├── bot.slnx
├── repo_tree.md
└── thirdParty
    ├── Scriptforge
    │   └── ScriptforgeLib
    │       ├── ScriptForge.ErrCode.ixx
    │       ├── Scriptforge.Argv.ixx
    │       ├── Scriptforge.Err.ixx
    │       ├── Scriptforge.ErrCode.throwError.ixx
    │       ├── Scriptforge.LanguageCode.ixx
    │       ├── Scriptforge.Local.ixx
    │       ├── Scriptforge.Msg.ixx
    │       ├── Scriptforge.Pch.ixx
    │       ├── Scriptforge.StringConversion.ixx
    │       └── Scriptforge.Version.ixx
    ├── asio
    │   ├── COPYING
    │   ├── INSTALL
    │   ├── LICENSE_1_0.txt
    │   ├── asio
    │   │   ├── any_io_executor.hpp
    │   │   ├── associated_allocator.hpp
    │   │   ├── associated_executor.hpp
    │   │   ├── async_result.hpp
    │   │   ├── awaitable.hpp
    │   │   ├── basic_datagram_socket.hpp
    │   │   ├── basic_deadline_timer.hpp
    │   │   ├── basic_io_object.hpp
    │   │   ├── basic_raw_socket.hpp
    │   │   ├── basic_seq_packet_socket.hpp
    │   │   ├── basic_serial_port.hpp
    │   │   ├── basic_signal_set.hpp
    │   │   ├── basic_socket.hpp
    │   │   ├── basic_socket_acceptor.hpp
    │   │   ├── basic_socket_iostream.hpp
    │   │   ├── basic_socket_streambuf.hpp
    │   │   ├── basic_stream_socket.hpp
    │   │   ├── basic_streambuf.hpp
    │   │   ├── basic_streambuf_fwd.hpp
    │   │   ├── basic_waitable_timer.hpp
    │   │   ├── bind_executor.hpp
    │   │   ├── buffer.hpp
    │   │   ├── buffered_read_stream.hpp
    │   │   ├── buffered_read_stream_fwd.hpp
    │   │   ├── buffered_stream.hpp
    │   │   ├── buffered_stream_fwd.hpp
    │   │   ├── buffered_write_stream.hpp
    │   │   ├── buffered_write_stream_fwd.hpp
    │   │   ├── buffers_iterator.hpp
    │   │   ├── co_spawn.hpp
    │   │   ├── completion_condition.hpp
    │   │   ├── compose.hpp
    │   │   ├── connect.hpp
    │   │   ├── coroutine.hpp
    │   │   ├── deadline_timer.hpp
    │   │   ├── defer.hpp
    │   │   ├── detached.hpp
    │   │   ├── detail
    │   │   │   ├── array.hpp
    │   │   │   ├── array_fwd.hpp
    │   │   │   ├── assert.hpp
    │   │   │   ├── atomic_count.hpp
    │   │   │   ├── base_from_completion_cond.hpp
    │   │   │   ├── bind_handler.hpp
    │   │   │   ├── blocking_executor_op.hpp
    │   │   │   ├── buffer_resize_guard.hpp
    │   │   │   ├── buffer_sequence_adapter.hpp
    │   │   │   ├── buffered_stream_storage.hpp
    │   │   │   ├── bulk_executor_op.hpp
    │   │   │   ├── call_stack.hpp
    │   │   │   ├── chrono.hpp
    │   │   │   ├── chrono_time_traits.hpp
    │   │   │   ├── completion_handler.hpp
    │   │   │   ├── concurrency_hint.hpp
    │   │   │   ├── conditionally_enabled_event.hpp
    │   │   │   ├── conditionally_enabled_mutex.hpp
    │   │   │   ├── config.hpp
    │   │   │   ├── consuming_buffers.hpp
    │   │   │   ├── cstddef.hpp
    │   │   │   ├── cstdint.hpp
    │   │   │   ├── date_time_fwd.hpp
    │   │   │   ├── deadline_timer_service.hpp
    │   │   │   ├── dependent_type.hpp
    │   │   │   ├── descriptor_ops.hpp
    │   │   │   ├── descriptor_read_op.hpp
    │   │   │   ├── descriptor_write_op.hpp
    │   │   │   ├── dev_poll_reactor.hpp
    │   │   │   ├── epoll_reactor.hpp
    │   │   │   ├── event.hpp
    │   │   │   ├── eventfd_select_interrupter.hpp
    │   │   │   ├── executor_function.hpp
    │   │   │   ├── executor_op.hpp
    │   │   │   ├── fd_set_adapter.hpp
    │   │   │   ├── fenced_block.hpp
    │   │   │   ├── functional.hpp
    │   │   │   ├── future.hpp
    │   │   │   ├── gcc_arm_fenced_block.hpp
    │   │   │   ├── gcc_hppa_fenced_block.hpp
    │   │   │   ├── gcc_sync_fenced_block.hpp
    │   │   │   ├── gcc_x86_fenced_block.hpp
    │   │   │   ├── global.hpp
    │   │   │   ├── handler_alloc_helpers.hpp
    │   │   │   ├── handler_cont_helpers.hpp
    │   │   │   ├── handler_invoke_helpers.hpp
    │   │   │   ├── handler_tracking.hpp
    │   │   │   ├── handler_type_requirements.hpp
    │   │   │   ├── handler_work.hpp
    │   │   │   ├── hash_map.hpp
    │   │   │   ├── impl
    │   │   │   │   ├── buffer_sequence_adapter.ipp
    │   │   │   │   ├── descriptor_ops.ipp
    │   │   │   │   ├── dev_poll_reactor.hpp
    │   │   │   │   ├── dev_poll_reactor.ipp
    │   │   │   │   ├── epoll_reactor.hpp
    │   │   │   │   ├── epoll_reactor.ipp
    │   │   │   │   ├── eventfd_select_interrupter.ipp
    │   │   │   │   ├── handler_tracking.ipp
    │   │   │   │   ├── kqueue_reactor.hpp
    │   │   │   │   ├── kqueue_reactor.ipp
    │   │   │   │   ├── null_event.ipp
    │   │   │   │   ├── pipe_select_interrupter.ipp
    │   │   │   │   ├── posix_event.ipp
    │   │   │   │   ├── posix_mutex.ipp
    │   │   │   │   ├── posix_thread.ipp
    │   │   │   │   ├── posix_tss_ptr.ipp
    │   │   │   │   ├── reactive_descriptor_service.ipp
    │   │   │   │   ├── reactive_serial_port_service.ipp
    │   │   │   │   ├── reactive_socket_service_base.ipp
    │   │   │   │   ├── resolver_service_base.ipp
    │   │   │   │   ├── scheduler.ipp
    │   │   │   │   ├── select_reactor.hpp
    │   │   │   │   ├── select_reactor.ipp
    │   │   │   │   ├── service_registry.hpp
    │   │   │   │   ├── service_registry.ipp
    │   │   │   │   ├── signal_set_service.ipp
    │   │   │   │   ├── socket_ops.ipp
    │   │   │   │   ├── socket_select_interrupter.ipp
    │   │   │   │   ├── strand_executor_service.hpp
    │   │   │   │   ├── strand_executor_service.ipp
    │   │   │   │   ├── strand_service.hpp
    │   │   │   │   ├── strand_service.ipp
    │   │   │   │   ├── thread_context.ipp
    │   │   │   │   ├── throw_error.ipp
    │   │   │   │   ├── timer_queue_ptime.ipp
    │   │   │   │   ├── timer_queue_set.ipp
    │   │   │   │   ├── win_event.ipp
    │   │   │   │   ├── win_iocp_handle_service.ipp
    │   │   │   │   ├── win_iocp_io_context.hpp
    │   │   │   │   ├── win_iocp_io_context.ipp
    │   │   │   │   ├── win_iocp_serial_port_service.ipp
    │   │   │   │   ├── win_iocp_socket_service_base.ipp
    │   │   │   │   ├── win_mutex.ipp
    │   │   │   │   ├── win_object_handle_service.ipp
    │   │   │   │   ├── win_static_mutex.ipp
    │   │   │   │   ├── win_thread.ipp
    │   │   │   │   ├── win_tss_ptr.ipp
    │   │   │   │   ├── winrt_ssocket_service_base.ipp
    │   │   │   │   ├── winrt_timer_scheduler.hpp
    │   │   │   │   ├── winrt_timer_scheduler.ipp
    │   │   │   │   └── winsock_init.ipp
    │   │   │   ├── io_control.hpp
    │   │   │   ├── io_object_impl.hpp
    │   │   │   ├── is_buffer_sequence.hpp
    │   │   │   ├── is_executor.hpp
    │   │   │   ├── keyword_tss_ptr.hpp
    │   │   │   ├── kqueue_reactor.hpp
    │   │   │   ├── limits.hpp
    │   │   │   ├── local_free_on_block_exit.hpp
    │   │   │   ├── macos_fenced_block.hpp
    │   │   │   ├── memory.hpp
    │   │   │   ├── mutex.hpp
    │   │   │   ├── non_const_lvalue.hpp
    │   │   │   ├── noncopyable.hpp
    │   │   │   ├── null_event.hpp
    │   │   │   ├── null_fenced_block.hpp
    │   │   │   ├── null_global.hpp
    │   │   │   ├── null_mutex.hpp
    │   │   │   ├── null_reactor.hpp
    │   │   │   ├── null_signal_blocker.hpp
    │   │   │   ├── null_socket_service.hpp
    │   │   │   ├── null_static_mutex.hpp
    │   │   │   ├── null_thread.hpp
    │   │   │   ├── null_tss_ptr.hpp
    │   │   │   ├── object_pool.hpp
    │   │   │   ├── old_win_sdk_compat.hpp
    │   │   │   ├── op_queue.hpp
    │   │   │   ├── operation.hpp
    │   │   │   ├── pipe_select_interrupter.hpp
    │   │   │   ├── pop_options.hpp
    │   │   │   ├── posix_event.hpp
    │   │   │   ├── posix_fd_set_adapter.hpp
    │   │   │   ├── posix_global.hpp
    │   │   │   ├── posix_mutex.hpp
    │   │   │   ├── posix_signal_blocker.hpp
    │   │   │   ├── posix_static_mutex.hpp
    │   │   │   ├── posix_thread.hpp
    │   │   │   ├── posix_tss_ptr.hpp
    │   │   │   ├── push_options.hpp
    │   │   │   ├── reactive_descriptor_service.hpp
    │   │   │   ├── reactive_null_buffers_op.hpp
    │   │   │   ├── reactive_serial_port_service.hpp
    │   │   │   ├── reactive_socket_accept_op.hpp
    │   │   │   ├── reactive_socket_connect_op.hpp
    │   │   │   ├── reactive_socket_recv_op.hpp
    │   │   │   ├── reactive_socket_recvfrom_op.hpp
    │   │   │   ├── reactive_socket_recvmsg_op.hpp
    │   │   │   ├── reactive_socket_send_op.hpp
    │   │   │   ├── reactive_socket_sendto_op.hpp
    │   │   │   ├── reactive_socket_service.hpp
    │   │   │   ├── reactive_socket_service_base.hpp
    │   │   │   ├── reactive_wait_op.hpp
    │   │   │   ├── reactor.hpp
    │   │   │   ├── reactor_fwd.hpp
    │   │   │   ├── reactor_op.hpp
    │   │   │   ├── reactor_op_queue.hpp
    │   │   │   ├── recycling_allocator.hpp
    │   │   │   ├── regex_fwd.hpp
    │   │   │   ├── resolve_endpoint_op.hpp
    │   │   │   ├── resolve_op.hpp
    │   │   │   ├── resolve_query_op.hpp
    │   │   │   ├── resolver_service.hpp
    │   │   │   ├── resolver_service_base.hpp
    │   │   │   ├── scheduler.hpp
    │   │   │   ├── scheduler_operation.hpp
    │   │   │   ├── scheduler_thread_info.hpp
    │   │   │   ├── scoped_lock.hpp
    │   │   │   ├── scoped_ptr.hpp
    │   │   │   ├── select_interrupter.hpp
    │   │   │   ├── select_reactor.hpp
    │   │   │   ├── service_registry.hpp
    │   │   │   ├── signal_blocker.hpp
    │   │   │   ├── signal_handler.hpp
    │   │   │   ├── signal_init.hpp
    │   │   │   ├── signal_op.hpp
    │   │   │   ├── signal_set_service.hpp
    │   │   │   ├── socket_holder.hpp
    │   │   │   ├── socket_ops.hpp
    │   │   │   ├── socket_option.hpp
    │   │   │   ├── socket_select_interrupter.hpp
    │   │   │   ├── socket_types.hpp
    │   │   │   ├── solaris_fenced_block.hpp
    │   │   │   ├── source_location.hpp
    │   │   │   ├── static_mutex.hpp
    │   │   │   ├── std_event.hpp
    │   │   │   ├── std_fenced_block.hpp
    │   │   │   ├── std_global.hpp
    │   │   │   ├── std_mutex.hpp
    │   │   │   ├── std_static_mutex.hpp
    │   │   │   ├── std_thread.hpp
    │   │   │   ├── strand_executor_service.hpp
    │   │   │   ├── strand_service.hpp
    │   │   │   ├── string_view.hpp
    │   │   │   ├── thread.hpp
    │   │   │   ├── thread_context.hpp
    │   │   │   ├── thread_group.hpp
    │   │   │   ├── thread_info_base.hpp
    │   │   │   ├── throw_error.hpp
    │   │   │   ├── throw_exception.hpp
    │   │   │   ├── timer_queue.hpp
    │   │   │   ├── timer_queue_base.hpp
    │   │   │   ├── timer_queue_ptime.hpp
    │   │   │   ├── timer_queue_set.hpp
    │   │   │   ├── timer_scheduler.hpp
    │   │   │   ├── timer_scheduler_fwd.hpp
    │   │   │   ├── tss_ptr.hpp
    │   │   │   ├── type_traits.hpp
    │   │   │   ├── variadic_templates.hpp
    │   │   │   ├── wait_handler.hpp
    │   │   │   ├── wait_op.hpp
    │   │   │   ├── win_event.hpp
    │   │   │   ├── win_fd_set_adapter.hpp
    │   │   │   ├── win_fenced_block.hpp
    │   │   │   ├── win_global.hpp
    │   │   │   ├── win_iocp_handle_read_op.hpp
    │   │   │   ├── win_iocp_handle_service.hpp
    │   │   │   ├── win_iocp_handle_write_op.hpp
    │   │   │   ├── win_iocp_io_context.hpp
    │   │   │   ├── win_iocp_null_buffers_op.hpp
    │   │   │   ├── win_iocp_operation.hpp
    │   │   │   ├── win_iocp_overlapped_op.hpp
    │   │   │   ├── win_iocp_overlapped_ptr.hpp
    │   │   │   ├── win_iocp_serial_port_service.hpp
    │   │   │   ├── win_iocp_socket_accept_op.hpp
    │   │   │   ├── win_iocp_socket_connect_op.hpp
    │   │   │   ├── win_iocp_socket_recv_op.hpp
    │   │   │   ├── win_iocp_socket_recvfrom_op.hpp
    │   │   │   ├── win_iocp_socket_recvmsg_op.hpp
    │   │   │   ├── win_iocp_socket_send_op.hpp
    │   │   │   ├── win_iocp_socket_service.hpp
    │   │   │   ├── win_iocp_socket_service_base.hpp
    │   │   │   ├── win_iocp_thread_info.hpp
    │   │   │   ├── win_iocp_wait_op.hpp
    │   │   │   ├── win_mutex.hpp
    │   │   │   ├── win_object_handle_service.hpp
    │   │   │   ├── win_static_mutex.hpp
    │   │   │   ├── win_thread.hpp
    │   │   │   ├── win_tss_ptr.hpp
    │   │   │   ├── winapp_thread.hpp
    │   │   │   ├── wince_thread.hpp
    │   │   │   ├── winrt_async_manager.hpp
    │   │   │   ├── winrt_async_op.hpp
    │   │   │   ├── winrt_resolve_op.hpp
    │   │   │   ├── winrt_resolver_service.hpp
    │   │   │   ├── winrt_socket_connect_op.hpp
    │   │   │   ├── winrt_socket_recv_op.hpp
    │   │   │   ├── winrt_socket_send_op.hpp
    │   │   │   ├── winrt_ssocket_service.hpp
    │   │   │   ├── winrt_ssocket_service_base.hpp
    │   │   │   ├── winrt_timer_scheduler.hpp
    │   │   │   ├── winrt_utils.hpp
    │   │   │   ├── winsock_init.hpp
    │   │   │   ├── work_dispatcher.hpp
    │   │   │   └── wrapped_handler.hpp
    │   │   ├── dispatch.hpp
    │   │   ├── error.hpp
    │   │   ├── error_code.hpp
    │   │   ├── execution
    │   │   │   ├── allocator.hpp
    │   │   │   ├── any_executor.hpp
    │   │   │   ├── bad_executor.hpp
    │   │   │   ├── blocking.hpp
    │   │   │   ├── blocking_adaptation.hpp
    │   │   │   ├── bulk_execute.hpp
    │   │   │   ├── bulk_guarantee.hpp
    │   │   │   ├── connect.hpp
    │   │   │   ├── context.hpp
    │   │   │   ├── context_as.hpp
    │   │   │   ├── detail
    │   │   │   │   ├── as_invocable.hpp
    │   │   │   │   ├── as_operation.hpp
    │   │   │   │   ├── as_receiver.hpp
    │   │   │   │   ├── bulk_sender.hpp
    │   │   │   │   ├── submit_receiver.hpp
    │   │   │   │   └── void_receiver.hpp
    │   │   │   ├── execute.hpp
    │   │   │   ├── executor.hpp
    │   │   │   ├── impl
    │   │   │   │   ├── bad_executor.ipp
    │   │   │   │   └── receiver_invocation_error.ipp
    │   │   │   ├── invocable_archetype.hpp
    │   │   │   ├── mapping.hpp
    │   │   │   ├── occupancy.hpp
    │   │   │   ├── operation_state.hpp
    │   │   │   ├── outstanding_work.hpp
    │   │   │   ├── prefer_only.hpp
    │   │   │   ├── receiver.hpp
    │   │   │   ├── receiver_invocation_error.hpp
    │   │   │   ├── relationship.hpp
    │   │   │   ├── schedule.hpp
    │   │   │   ├── scheduler.hpp
    │   │   │   ├── sender.hpp
    │   │   │   ├── set_done.hpp
    │   │   │   ├── set_error.hpp
    │   │   │   ├── set_value.hpp
    │   │   │   ├── start.hpp
    │   │   │   └── submit.hpp
    │   │   ├── execution.hpp
    │   │   ├── execution_context.hpp
    │   │   ├── executor.hpp
    │   │   ├── executor_work_guard.hpp
    │   │   ├── experimental
    │   │   │   ├── as_single.hpp
    │   │   │   └── impl
    │   │   │       └── as_single.hpp
    │   │   ├── generic
    │   │   │   ├── basic_endpoint.hpp
    │   │   │   ├── datagram_protocol.hpp
    │   │   │   ├── detail
    │   │   │   │   ├── endpoint.hpp
    │   │   │   │   └── impl
    │   │   │   │       └── endpoint.ipp
    │   │   │   ├── raw_protocol.hpp
    │   │   │   ├── seq_packet_protocol.hpp
    │   │   │   └── stream_protocol.hpp
    │   │   ├── handler_alloc_hook.hpp
    │   │   ├── handler_continuation_hook.hpp
    │   │   ├── handler_invoke_hook.hpp
    │   │   ├── high_resolution_timer.hpp
    │   │   ├── impl
    │   │   │   ├── awaitable.hpp
    │   │   │   ├── buffered_read_stream.hpp
    │   │   │   ├── buffered_write_stream.hpp
    │   │   │   ├── co_spawn.hpp
    │   │   │   ├── compose.hpp
    │   │   │   ├── connect.hpp
    │   │   │   ├── defer.hpp
    │   │   │   ├── detached.hpp
    │   │   │   ├── dispatch.hpp
    │   │   │   ├── error.ipp
    │   │   │   ├── error_code.ipp
    │   │   │   ├── execution_context.hpp
    │   │   │   ├── execution_context.ipp
    │   │   │   ├── executor.hpp
    │   │   │   ├── executor.ipp
    │   │   │   ├── handler_alloc_hook.ipp
    │   │   │   ├── io_context.hpp
    │   │   │   ├── io_context.ipp
    │   │   │   ├── multiple_exceptions.ipp
    │   │   │   ├── post.hpp
    │   │   │   ├── read.hpp
    │   │   │   ├── read_at.hpp
    │   │   │   ├── read_until.hpp
    │   │   │   ├── redirect_error.hpp
    │   │   │   ├── serial_port_base.hpp
    │   │   │   ├── serial_port_base.ipp
    │   │   │   ├── spawn.hpp
    │   │   │   ├── src.hpp
    │   │   │   ├── system_context.hpp
    │   │   │   ├── system_context.ipp
    │   │   │   ├── system_executor.hpp
    │   │   │   ├── thread_pool.hpp
    │   │   │   ├── thread_pool.ipp
    │   │   │   ├── use_awaitable.hpp
    │   │   │   ├── use_future.hpp
    │   │   │   ├── write.hpp
    │   │   │   └── write_at.hpp
    │   │   ├── io_context.hpp
    │   │   ├── io_context_strand.hpp
    │   │   ├── io_service.hpp
    │   │   ├── io_service_strand.hpp
    │   │   ├── ip
    │   │   │   ├── address.hpp
    │   │   │   ├── address_v4.hpp
    │   │   │   ├── address_v4_iterator.hpp
    │   │   │   ├── address_v4_range.hpp
    │   │   │   ├── address_v6.hpp
    │   │   │   ├── address_v6_iterator.hpp
    │   │   │   ├── address_v6_range.hpp
    │   │   │   ├── bad_address_cast.hpp
    │   │   │   ├── basic_endpoint.hpp
    │   │   │   ├── basic_resolver.hpp
    │   │   │   ├── basic_resolver_entry.hpp
    │   │   │   ├── basic_resolver_iterator.hpp
    │   │   │   ├── basic_resolver_query.hpp
    │   │   │   ├── basic_resolver_results.hpp
    │   │   │   ├── detail
    │   │   │   │   ├── endpoint.hpp
    │   │   │   │   ├── impl
    │   │   │   │   │   └── endpoint.ipp
    │   │   │   │   └── socket_option.hpp
    │   │   │   ├── host_name.hpp
    │   │   │   ├── icmp.hpp
    │   │   │   ├── impl
    │   │   │   │   ├── address.hpp
    │   │   │   │   ├── address.ipp
    │   │   │   │   ├── address_v4.hpp
    │   │   │   │   ├── address_v4.ipp
    │   │   │   │   ├── address_v6.hpp
    │   │   │   │   ├── address_v6.ipp
    │   │   │   │   ├── basic_endpoint.hpp
    │   │   │   │   ├── host_name.ipp
    │   │   │   │   ├── network_v4.hpp
    │   │   │   │   ├── network_v4.ipp
    │   │   │   │   ├── network_v6.hpp
    │   │   │   │   └── network_v6.ipp
    │   │   │   ├── multicast.hpp
    │   │   │   ├── network_v4.hpp
    │   │   │   ├── network_v6.hpp
    │   │   │   ├── resolver_base.hpp
    │   │   │   ├── resolver_query_base.hpp
    │   │   │   ├── tcp.hpp
    │   │   │   ├── udp.hpp
    │   │   │   ├── unicast.hpp
    │   │   │   └── v6_only.hpp
    │   │   ├── is_applicable_property.hpp
    │   │   ├── is_executor.hpp
    │   │   ├── is_read_buffered.hpp
    │   │   ├── is_write_buffered.hpp
    │   │   ├── local
    │   │   │   ├── basic_endpoint.hpp
    │   │   │   ├── connect_pair.hpp
    │   │   │   ├── datagram_protocol.hpp
    │   │   │   ├── detail
    │   │   │   │   ├── endpoint.hpp
    │   │   │   │   └── impl
    │   │   │   │       └── endpoint.ipp
    │   │   │   └── stream_protocol.hpp
    │   │   ├── multiple_exceptions.hpp
    │   │   ├── packaged_task.hpp
    │   │   ├── placeholders.hpp
    │   │   ├── posix
    │   │   │   ├── basic_descriptor.hpp
    │   │   │   ├── basic_stream_descriptor.hpp
    │   │   │   ├── descriptor.hpp
    │   │   │   ├── descriptor_base.hpp
    │   │   │   └── stream_descriptor.hpp
    │   │   ├── post.hpp
    │   │   ├── prefer.hpp
    │   │   ├── query.hpp
    │   │   ├── read.hpp
    │   │   ├── read_at.hpp
    │   │   ├── read_until.hpp
    │   │   ├── redirect_error.hpp
    │   │   ├── require.hpp
    │   │   ├── require_concept.hpp
    │   │   ├── serial_port.hpp
    │   │   ├── serial_port_base.hpp
    │   │   ├── signal_set.hpp
    │   │   ├── socket_base.hpp
    │   │   ├── spawn.hpp
    │   │   ├── ssl
    │   │   │   ├── context.hpp
    │   │   │   ├── context_base.hpp
    │   │   │   ├── detail
    │   │   │   │   ├── buffered_handshake_op.hpp
    │   │   │   │   ├── engine.hpp
    │   │   │   │   ├── handshake_op.hpp
    │   │   │   │   ├── impl
    │   │   │   │   │   ├── engine.ipp
    │   │   │   │   │   └── openssl_init.ipp
    │   │   │   │   ├── io.hpp
    │   │   │   │   ├── openssl_init.hpp
    │   │   │   │   ├── openssl_types.hpp
    │   │   │   │   ├── password_callback.hpp
    │   │   │   │   ├── read_op.hpp
    │   │   │   │   ├── shutdown_op.hpp
    │   │   │   │   ├── stream_core.hpp
    │   │   │   │   ├── verify_callback.hpp
    │   │   │   │   └── write_op.hpp
    │   │   │   ├── error.hpp
    │   │   │   ├── host_name_verification.hpp
    │   │   │   ├── impl
    │   │   │   │   ├── context.hpp
    │   │   │   │   ├── context.ipp
    │   │   │   │   ├── error.ipp
    │   │   │   │   ├── host_name_verification.ipp
    │   │   │   │   ├── rfc2818_verification.ipp
    │   │   │   │   └── src.hpp
    │   │   │   ├── rfc2818_verification.hpp
    │   │   │   ├── stream.hpp
    │   │   │   ├── stream_base.hpp
    │   │   │   ├── verify_context.hpp
    │   │   │   └── verify_mode.hpp
    │   │   ├── ssl.hpp
    │   │   ├── static_thread_pool.hpp
    │   │   ├── steady_timer.hpp
    │   │   ├── strand.hpp
    │   │   ├── streambuf.hpp
    │   │   ├── system_context.hpp
    │   │   ├── system_error.hpp
    │   │   ├── system_executor.hpp
    │   │   ├── system_timer.hpp
    │   │   ├── this_coro.hpp
    │   │   ├── thread.hpp
    │   │   ├── thread_pool.hpp
    │   │   ├── time_traits.hpp
    │   │   ├── traits
    │   │   │   ├── bulk_execute_free.hpp
    │   │   │   ├── bulk_execute_member.hpp
    │   │   │   ├── connect_free.hpp
    │   │   │   ├── connect_member.hpp
    │   │   │   ├── equality_comparable.hpp
    │   │   │   ├── execute_free.hpp
    │   │   │   ├── execute_member.hpp
    │   │   │   ├── prefer_free.hpp
    │   │   │   ├── prefer_member.hpp
    │   │   │   ├── query_free.hpp
    │   │   │   ├── query_member.hpp
    │   │   │   ├── query_static_constexpr_member.hpp
    │   │   │   ├── require_concept_free.hpp
    │   │   │   ├── require_concept_member.hpp
    │   │   │   ├── require_free.hpp
    │   │   │   ├── require_member.hpp
    │   │   │   ├── schedule_free.hpp
    │   │   │   ├── schedule_member.hpp
    │   │   │   ├── set_done_free.hpp
    │   │   │   ├── set_done_member.hpp
    │   │   │   ├── set_error_free.hpp
    │   │   │   ├── set_error_member.hpp
    │   │   │   ├── set_value_free.hpp
    │   │   │   ├── set_value_member.hpp
    │   │   │   ├── start_free.hpp
    │   │   │   ├── start_member.hpp
    │   │   │   ├── static_query.hpp
    │   │   │   ├── static_require.hpp
    │   │   │   ├── static_require_concept.hpp
    │   │   │   ├── submit_free.hpp
    │   │   │   └── submit_member.hpp
    │   │   ├── ts
    │   │   │   ├── buffer.hpp
    │   │   │   ├── executor.hpp
    │   │   │   ├── internet.hpp
    │   │   │   ├── io_context.hpp
    │   │   │   ├── net.hpp
    │   │   │   ├── netfwd.hpp
    │   │   │   ├── socket.hpp
    │   │   │   └── timer.hpp
    │   │   ├── unyield.hpp
    │   │   ├── use_awaitable.hpp
    │   │   ├── use_future.hpp
    │   │   ├── uses_executor.hpp
    │   │   ├── version.hpp
    │   │   ├── wait_traits.hpp
    │   │   ├── windows
    │   │   │   ├── basic_object_handle.hpp
    │   │   │   ├── basic_overlapped_handle.hpp
    │   │   │   ├── basic_random_access_handle.hpp
    │   │   │   ├── basic_stream_handle.hpp
    │   │   │   ├── object_handle.hpp
    │   │   │   ├── overlapped_handle.hpp
    │   │   │   ├── overlapped_ptr.hpp
    │   │   │   ├── random_access_handle.hpp
    │   │   │   └── stream_handle.hpp
    │   │   ├── write.hpp
    │   │   ├── write_at.hpp
    │   │   └── yield.hpp
    │   └── asio.hpp
    ├── json
    │   ├── json.cppm
    │   └── nlohmann
    │       ├── json.hpp
    │       └── json_fwd.hpp
    ├── utf8
    │   ├── utf8
    │   │   ├── checked.h
    │   │   ├── core.h
    │   │   ├── cpp11.h
    │   │   ├── cpp17.h
    │   │   ├── cpp20.h
    │   │   └── unchecked.h
    │   └── utf8.h
    └── websocketpp
        ├── COPYING
        ├── base64
        │   └── base64.hpp
        ├── client.hpp
        ├── close.hpp
        ├── common
        │   ├── asio.hpp
        │   ├── asio_ssl.hpp
        │   ├── chrono.hpp
        │   ├── connection_hdl.hpp
        │   ├── cpp11.hpp
        │   ├── functional.hpp
        │   ├── md5.hpp
        │   ├── memory.hpp
        │   ├── network.hpp
        │   ├── platforms.hpp
        │   ├── random.hpp
        │   ├── regex.hpp
        │   ├── stdint.hpp
        │   ├── system_error.hpp
        │   ├── thread.hpp
        │   ├── time.hpp
        │   └── type_traits.hpp
        ├── concurrency
        │   ├── basic.hpp
        │   └── none.hpp
        ├── config
        │   ├── asio.hpp
        │   ├── asio_client.hpp
        │   ├── asio_no_tls.hpp
        │   ├── asio_no_tls_client.hpp
        │   ├── boost_config.hpp
        │   ├── core.hpp
        │   ├── core_client.hpp
        │   ├── debug.hpp
        │   ├── debug_asio.hpp
        │   ├── debug_asio_no_tls.hpp
        │   ├── minimal_client.hpp
        │   └── minimal_server.hpp
        ├── connection.hpp
        ├── connection_base.hpp
        ├── endpoint.hpp
        ├── endpoint_base.hpp
        ├── error.hpp
        ├── extensions
        │   ├── extension.hpp
        │   └── permessage_deflate
        │       ├── disabled.hpp
        │       └── enabled.hpp
        ├── frame.hpp
        ├── http
        │   ├── constants.hpp
        │   ├── impl
        │   │   ├── parser.hpp
        │   │   ├── request.hpp
        │   │   └── response.hpp
        │   ├── parser.hpp
        │   ├── request.hpp
        │   └── response.hpp
        ├── impl
        │   ├── connection_impl.hpp
        │   ├── endpoint_impl.hpp
        │   └── utilities_impl.hpp
        ├── logger
        │   ├── basic.hpp
        │   ├── levels.hpp
        │   ├── stub.hpp
        │   └── syslog.hpp
        ├── message_buffer
        │   ├── alloc.hpp
        │   ├── message.hpp
        │   └── pool.hpp
        ├── processors
        │   ├── base.hpp
        │   ├── hybi00.hpp
        │   ├── hybi07.hpp
        │   ├── hybi08.hpp
        │   ├── hybi13.hpp
        │   └── processor.hpp
        ├── random
        │   ├── none.hpp
        │   └── random_device.hpp
        ├── roles
        │   ├── client_endpoint.hpp
        │   └── server_endpoint.hpp
        ├── server.hpp
        ├── sha1
        │   └── sha1.hpp
        ├── transport
        │   ├── asio
        │   │   ├── base.hpp
        │   │   ├── connection.hpp
        │   │   ├── endpoint.hpp
        │   │   └── security
        │   │       ├── base.hpp
        │   │       ├── none.hpp
        │   │       └── tls.hpp
        │   ├── base
        │   │   ├── connection.hpp
        │   │   └── endpoint.hpp
        │   ├── debug
        │   │   ├── base.hpp
        │   │   ├── connection.hpp
        │   │   └── endpoint.hpp
        │   ├── iostream
        │   │   ├── base.hpp
        │   │   ├── connection.hpp
        │   │   └── endpoint.hpp
        │   └── stub
        │       ├── base.hpp
        │       ├── connection.hpp
        │       └── endpoint.hpp
        ├── uri.hpp
        ├── utf8_validator.hpp
        ├── utilities.hpp
        └── version.hpp
```

<!-- TREE_END -->