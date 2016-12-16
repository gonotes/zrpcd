/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef BGP_UPDATER_H
#define BGP_UPDATER_H

#include <thrift/c_glib/processor/thrift_dispatch_processor.h>

#include "vpnservice_types.h"

/* BgpUpdater service interface */
typedef struct _BgpUpdaterIf BgpUpdaterIf;  /* dummy object */

struct _BgpUpdaterIfInterface
{
  GTypeInterface parent;

  gboolean (*on_update_push_route) (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, const gchar * routermac, const gchar * gatewayip, GError **error);
  gboolean (*on_update_withdraw_route) (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, GError **error);
  gboolean (*on_start_config_resync_notification) (BgpUpdaterIf *iface, GError **error);
  gboolean (*on_notification_send_event) (BgpUpdaterIf *iface, const gchar * prefix, const gint8 errCode, const gint8 errSubcode, GError **error);
};
typedef struct _BgpUpdaterIfInterface BgpUpdaterIfInterface;

GType bgp_updater_if_get_type (void);
#define TYPE_BGP_UPDATER_IF (bgp_updater_if_get_type())
#define BGP_UPDATER_IF(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BGP_UPDATER_IF, BgpUpdaterIf))
#define IS_BGP_UPDATER_IF(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BGP_UPDATER_IF))
#define BGP_UPDATER_IF_GET_INTERFACE(inst) (G_TYPE_INSTANCE_GET_INTERFACE ((inst), TYPE_BGP_UPDATER_IF, BgpUpdaterIfInterface))

gboolean bgp_updater_if_on_update_push_route (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, const gchar * routermac, const gchar * gatewayip, GError **error);
gboolean bgp_updater_if_on_update_withdraw_route (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, GError **error);
gboolean bgp_updater_if_on_start_config_resync_notification (BgpUpdaterIf *iface, GError **error);
gboolean bgp_updater_if_on_notification_send_event (BgpUpdaterIf *iface, const gchar * prefix, const gint8 errCode, const gint8 errSubcode, GError **error);

/* BgpUpdater service client */
struct _BgpUpdaterClient
{
  GObject parent;

  ThriftProtocol *input_protocol;
  ThriftProtocol *output_protocol;
};
typedef struct _BgpUpdaterClient BgpUpdaterClient;

struct _BgpUpdaterClientClass
{
  GObjectClass parent;
};
typedef struct _BgpUpdaterClientClass BgpUpdaterClientClass;

GType bgp_updater_client_get_type (void);
#define TYPE_BGP_UPDATER_CLIENT (bgp_updater_client_get_type())
#define BGP_UPDATER_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BGP_UPDATER_CLIENT, BgpUpdaterClient))
#define BGP_UPDATER_CLIENT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), TYPE_BGP_UPDATER_CLIENT, BgpUpdaterClientClass))
#define BGP_UPDATER_IS_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BGP_UPDATER_CLIENT))
#define BGP_UPDATER_IS_CLIENT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), TYPE_BGP_UPDATER_CLIENT))
#define BGP_UPDATER_CLIENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BGP_UPDATER_CLIENT, BgpUpdaterClientClass))

gboolean bgp_updater_client_on_update_push_route (BgpUpdaterIf * iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, const gchar * routermac, const gchar * gatewayip, GError ** error);
gboolean bgp_updater_client_send_on_update_push_route (BgpUpdaterIf * iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, const gchar * routermac, const gchar * gatewayip, GError ** error);
gboolean bgp_updater_client_on_update_withdraw_route (BgpUpdaterIf * iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, GError ** error);
gboolean bgp_updater_client_send_on_update_withdraw_route (BgpUpdaterIf * iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, GError ** error);
gboolean bgp_updater_client_on_start_config_resync_notification (BgpUpdaterIf * iface, GError ** error);
gboolean bgp_updater_client_send_on_start_config_resync_notification (BgpUpdaterIf * iface, GError ** error);
gboolean bgp_updater_client_on_notification_send_event (BgpUpdaterIf * iface, const gchar * prefix, const gint8 errCode, const gint8 errSubcode, GError ** error);
gboolean bgp_updater_client_send_on_notification_send_event (BgpUpdaterIf * iface, const gchar * prefix, const gint8 errCode, const gint8 errSubcode, GError ** error);
void bgp_updater_client_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
void bgp_updater_client_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

/* BgpUpdater handler (abstract base class) */
struct _BgpUpdaterHandler
{
  GObject parent;
};
typedef struct _BgpUpdaterHandler BgpUpdaterHandler;

struct _BgpUpdaterHandlerClass
{
  GObjectClass parent;

  gboolean (*on_update_push_route) (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, const gchar * routermac, const gchar * gatewayip, GError **error);
  gboolean (*on_update_withdraw_route) (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, GError **error);
  gboolean (*on_start_config_resync_notification) (BgpUpdaterIf *iface, GError **error);
  gboolean (*on_notification_send_event) (BgpUpdaterIf *iface, const gchar * prefix, const gint8 errCode, const gint8 errSubcode, GError **error);
};
typedef struct _BgpUpdaterHandlerClass BgpUpdaterHandlerClass;

GType bgp_updater_handler_get_type (void);
#define TYPE_BGP_UPDATER_HANDLER (bgp_updater_handler_get_type())
#define BGP_UPDATER_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BGP_UPDATER_HANDLER, BgpUpdaterHandler))
#define IS_BGP_UPDATER_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BGP_UPDATER_HANDLER))
#define BGP_UPDATER_HANDLER_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), TYPE_BGP_UPDATER_HANDLER, BgpUpdaterHandlerClass))
#define IS_BGP_UPDATER_HANDLER_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), TYPE_BGP_UPDATER_HANDLER))
#define BGP_UPDATER_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BGP_UPDATER_HANDLER, BgpUpdaterHandlerClass))

gboolean bgp_updater_handler_on_update_push_route (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, const gchar * routermac, const gchar * gatewayip, GError **error);
gboolean bgp_updater_handler_on_update_withdraw_route (BgpUpdaterIf *iface, const protocol_type p_type, const gchar * rd, const gchar * prefix, const gint32 prefixlen, const gchar * nexthop, const gint64 ethtag, const gchar * esi, const gchar * macaddress, const gint32 l3label, const gint32 l2label, GError **error);
gboolean bgp_updater_handler_on_start_config_resync_notification (BgpUpdaterIf *iface, GError **error);
gboolean bgp_updater_handler_on_notification_send_event (BgpUpdaterIf *iface, const gchar * prefix, const gint8 errCode, const gint8 errSubcode, GError **error);

/* BgpUpdater processor */
struct _BgpUpdaterProcessor
{
  ThriftDispatchProcessor parent;

  /* protected */
  BgpUpdaterHandler *handler;
  GHashTable *process_map;
};
typedef struct _BgpUpdaterProcessor BgpUpdaterProcessor;

struct _BgpUpdaterProcessorClass
{
  ThriftDispatchProcessorClass parent;

  /* protected */
  gboolean (*dispatch_call) (ThriftDispatchProcessor *processor,
                             ThriftProtocol *in,
                             ThriftProtocol *out,
                             gchar *fname,
                             gint32 seqid,
                             GError **error);
};
typedef struct _BgpUpdaterProcessorClass BgpUpdaterProcessorClass;

GType bgp_updater_processor_get_type (void);
#define TYPE_BGP_UPDATER_PROCESSOR (bgp_updater_processor_get_type())
#define BGP_UPDATER_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BGP_UPDATER_PROCESSOR, BgpUpdaterProcessor))
#define IS_BGP_UPDATER_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BGP_UPDATER_PROCESSOR))
#define BGP_UPDATER_PROCESSOR_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), TYPE_BGP_UPDATER_PROCESSOR, BgpUpdaterProcessorClass))
#define IS_BGP_UPDATER_PROCESSOR_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), TYPE_BGP_UPDATER_PROCESSOR))
#define BGP_UPDATER_PROCESSOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BGP_UPDATER_PROCESSOR, BgpUpdaterProcessorClass))

#endif /* BGP_UPDATER_H */
