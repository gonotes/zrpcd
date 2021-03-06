/*
 * AUTOGENERATED FILE - DO NOT EDIT
 * derived from GPLv2+ sources
 *
 * Copyright (c) 2016 6WIND,
 * This file is part of ZRPC daemon.
 * See the LICENSE file.
 */

#include <stdbool.h>
#include "capnp_c.h"
#include "zrpcd/zrpc_bgp_capnp.h"

static const capn_text capn_val0 = {0, ""};

capn_ptr qcapn_new_BGP(struct capn_segment *s)
{
    return capn_new_struct(s, 34, 5);
}

void qcapn_BGP_write(const struct bgp *s, capn_ptr p)
{
    capn_resolve(&p);
    capn_write32(p, 0, s->as);
    { capn_text tp = { .str = s->name, .len = s->name ? strlen(s->name) : 0 }; capn_set_text(p, 0, tp); }

    {
        capn_ptr tempptr = capn_new_struct(p.seg, 8, 0);
        capn_write32(tempptr, 0, ntohl(s->router_id_static.s_addr));
        capn_setp(p, 1, tempptr);
    }
    capn_write1(p, 32, !!(s->flags & BGP_FLAG_ALWAYS_COMPARE_MED));
    capn_write1(p, 33, !!(s->flags & BGP_FLAG_DETERMINISTIC_MED));
    capn_write1(p, 34, !!(s->flags & BGP_FLAG_MED_MISSING_AS_WORST));
    capn_write1(p, 35, !!(s->flags & BGP_FLAG_MED_CONFED));
    capn_write1(p, 36, !!(s->flags & BGP_FLAG_NO_DEFAULT_IPV4));
    capn_write1(p, 37, !!(s->flags & BGP_FLAG_NO_CLIENT_TO_CLIENT));
    capn_write1(p, 38, !!(s->flags & BGP_FLAG_ENFORCE_FIRST_AS));
    capn_write1(p, 39, !!(s->flags & BGP_FLAG_COMPARE_ROUTER_ID));
    capn_write1(p, 40, !!(s->flags & BGP_FLAG_ASPATH_IGNORE));
    capn_write1(p, 41, !!(s->flags & BGP_FLAG_IMPORT_CHECK));
    capn_write1(p, 42, !!(s->flags & BGP_FLAG_NO_FAST_EXT_FAILOVER));
    capn_write1(p, 43, !!(s->flags & BGP_FLAG_LOG_NEIGHBOR_CHANGES));
    capn_write1(p, 44, !!(s->flags & BGP_FLAG_GRACEFUL_RESTART));
    capn_write1(p, 45, !!(s->flags & BGP_FLAG_ASPATH_CONFED));
    capn_write1(p, 46, !!(s->flags & BGP_FLAG_ASPATH_MULTIPATH_RELAX));
    capn_write1(p, 47, !!(s->flags & BGP_FLAG_GR_PRESERVE_FWD));
    capn_write8(p, 6, s->distance_ebgp);
    capn_write8(p, 7, s->distance_ibgp);
    capn_write8(p, 8, s->distance_local);
    capn_write32(p, 12, s->default_local_pref);
    capn_write32(p, 16, s->default_holdtime);
    capn_write32(p, 20, s->default_keepalive);
    capn_write32(p, 24, s->restart_time);
    capn_write32(p, 28, s->stalepath_time);
    capn_write16(p, 32, s->v_update_delay);
    { capn_text tp = { .str = s->notify_zmq_url, .len = s->notify_zmq_url ? strlen(s->notify_zmq_url) : 0 }; capn_set_text(p, 2, tp); }
    { capn_text tp = { .str = s->logFile, .len = s->logFile ? strlen(s->logFile) : 0 }; capn_set_text(p, 3, tp); }
    { capn_text tp = { .str = s->logLevel, .len = s->logLevel ? strlen(s->logLevel) : 0 }; capn_set_text(p, 4, tp); }
}

void qcapn_BGPAfiSafi_write(const struct bgp *s, capn_ptr p, address_family_t afi, subsequent_address_family_t safi)
{
    capn_resolve(&p);

    capn_write1(p, 0, !!(s->af_flags[afi][safi] & BGP_CONFIG_DAMPENING));
    capn_write1(p, 1, !!(s->af_flags[afi][safi] & BGP_CONFIG_ASPATH_MULTIPATH_RELAX));
    capn_write1(p, 2, !!(s->af_flags[afi][safi] & BGP_CONFIG_MULTIPATH));
}


void qcapn_BGPVRF_read(struct bgp_vrf *s, capn_ptr p)
{
    uint64_t tmp;

    capn_resolve(&p);
    tmp = capn_read64(p, 0);
    memcpy(&s->outbound_rd.val, &tmp, 8);
    s->outbound_rd.family = AF_UNSPEC;
    s->outbound_rd.prefixlen = 64;
    s->max_mpath = capn_read32(p, 8);
    s->ltype = capn_read8(p, 12);
    {
        capn_ptr tmp_p = capn_getp(p, 0, 1);
        capn_list64 listptr = { .p = capn_getp(tmp_p, 0, 1) };
        size_t listsize = capn_len(listptr);
        uint64_t buf[listsize];
        capn_getv64(listptr, 0, buf, listsize);
        if (s->rt_import)
          zrpc_util_rdrt_free (s->rt_import);
        s->rt_import = zrpc_util_rdrt_import ((u_char *)buf, listsize);
    }

    {
        capn_ptr tmp_p = capn_getp(p, 1, 1);
        capn_list64 listptr = { .p = capn_getp(tmp_p, 0, 1) };
        size_t listsize = capn_len(listptr);
        uint64_t buf[listsize];
        capn_getv64(listptr, 0, buf, listsize);
        if (s->rt_export)
          zrpc_util_rdrt_free (s->rt_export);
        s->rt_export = zrpc_util_rdrt_import ((u_char *)buf, listsize);
    }
}

void qcapn_BGPVRF_write(const struct bgp_vrf *s, capn_ptr p)
{
    uint64_t tmp;

    memcpy(&tmp,&(s->outbound_rd.val), 8);
    capn_resolve(&p);
    capn_write64(p, 0, tmp);
    capn_write32(p, 8, s->max_mpath);
    capn_write8(p, 12, s->ltype);
    {
        capn_ptr tempptr = capn_new_struct(p.seg, 0, 1);
        size_t size = s->rt_import ? s->rt_import->size : 0;
        capn_list64 listptr = capn_new_list64(p.seg, size);
        if (size)
            capn_setv64(listptr, 0, (uint64_t *)s->rt_import->val, size);
        capn_setp(tempptr, 0, listptr.p);
        capn_setp(p, 0, tempptr);
    }
    {
        capn_ptr tempptr = capn_new_struct(p.seg, 0, 1);
        size_t size = s->rt_export ? s->rt_export->size : 0;
        capn_list64 listptr = capn_new_list64(p.seg, size);
        if (size)
            capn_setv64(listptr, 0, (uint64_t *)s->rt_export->val, size);
        capn_setp(tempptr, 0, listptr.p);
        capn_setp(p, 1, tempptr);
    }
}

capn_ptr qcapn_new_BGPVRF(struct capn_segment *s)
{
    return capn_new_struct(s, 13, 2);
}

void qcapn_BGPPeer_read(struct peer *s, capn_ptr p)
{
    capn_resolve(&p);
    s->as = capn_read32(p, 0);
    {
      capn_text tp = capn_get_text(p, 0, capn_val0);
      if (tp.len)
        {
          if (s->host)
            free(s->host);
          s->host = strdup(tp.str);
        }
    }
    {
      capn_text tp = capn_get_text(p, 1, capn_val0);
      if (tp.len)
        {
          if (s->desc)
            free(s->desc);
          s->desc = strdup(tp.str);
        }
    }
    s->port = capn_read16(p, 4);
    s->weight = capn_read32(p, 8);
    s->holdtime = capn_read32(p, 12);
    s->keepalive = capn_read32(p, 16);
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 0));
      if (tmp) s->flags |=  PEER_FLAG_PASSIVE;
      else     s->flags &= ~PEER_FLAG_PASSIVE;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 1));
      if (tmp) s->flags |=  PEER_FLAG_SHUTDOWN;
      else     s->flags &= ~PEER_FLAG_SHUTDOWN;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 2));
      if (tmp) s->flags |=  PEER_FLAG_DONT_CAPABILITY;
      else     s->flags &= ~PEER_FLAG_DONT_CAPABILITY;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 3));
      if (tmp) s->flags |=  PEER_FLAG_OVERRIDE_CAPABILITY;
      else     s->flags &= ~PEER_FLAG_OVERRIDE_CAPABILITY;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 4));
      if (tmp) s->flags |=  PEER_FLAG_STRICT_CAP_MATCH;
      else     s->flags &= ~PEER_FLAG_STRICT_CAP_MATCH;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 5));
      if (tmp) s->flags |=  PEER_FLAG_DYNAMIC_CAPABILITY;
      else     s->flags &= ~PEER_FLAG_DYNAMIC_CAPABILITY;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 6));
      if (tmp) s->flags |=  PEER_FLAG_DISABLE_CONNECTED_CHECK;
      else     s->flags &= ~PEER_FLAG_DISABLE_CONNECTED_CHECK;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 6) & (1 << 7));
      if (tmp) s->flags |=  PEER_FLAG_USE_CONFIGURED_SOURCE;
      else     s->flags &= ~PEER_FLAG_USE_CONFIGURED_SOURCE;
    }
    s->ttl = capn_read32(p, 20);
    {
      const char * update_source = NULL;
      int len;
      capn_text tp = capn_get_text(p, 2, capn_val0);
      update_source = tp.str;
      len = tp.len;
      if (update_source && len != 0)
        {
          s->update_source = strdup(update_source);
        }
      else
        {
          s->update_source = NULL;
        }
    }
}

void qcapn_BGPPeer_write(const struct peer *s, capn_ptr p)
{
    capn_resolve(&p);
    capn_write32(p, 0, s->as);
    { capn_text tp = { .str = s->host, .len = s->host ? strlen(s->host) : 0 }; capn_set_text(p, 0, tp); }
    { capn_text tp = { .str = s->desc, .len = s->desc ? strlen(s->desc) : 0 }; capn_set_text(p, 1, tp); }
    capn_write16(p, 4, s->port);
    capn_write32(p, 8, s->weight);
    capn_write32(p, 12, s->holdtime);
    capn_write32(p, 16, s->keepalive);
    capn_write1(p, 48, !!(s->flags & PEER_FLAG_PASSIVE));
    capn_write1(p, 49, !!(s->flags & PEER_FLAG_SHUTDOWN));
    capn_write1(p, 50, !!(s->flags & PEER_FLAG_DONT_CAPABILITY));
    capn_write1(p, 51, !!(s->flags & PEER_FLAG_OVERRIDE_CAPABILITY));
    capn_write1(p, 52, !!(s->flags & PEER_FLAG_STRICT_CAP_MATCH));
    capn_write1(p, 53, !!(s->flags & PEER_FLAG_DYNAMIC_CAPABILITY));
    capn_write1(p, 54, !!(s->flags & PEER_FLAG_DISABLE_CONNECTED_CHECK));
    capn_write1(p, 55, !!(s->flags & PEER_FLAG_USE_CONFIGURED_SOURCE));
    capn_write32(p, 20, s->ttl);
    {
      capn_text tp;
      if(s->update_source)
        {
          tp.str = strdup (s->update_source);
          tp.len = strlen(s->update_source);
        } else
        {
          tp.str = NULL;
          tp.len = 0;
        }
      capn_set_text(p, 2, tp);
    }
}

capn_ptr qcapn_new_BGPPeer(struct capn_segment *s)
{
    return capn_new_struct(s, 24, 3);
}

capn_ptr qcapn_new_AfiSafiKey(struct capn_segment *s)
{
    return capn_new_struct(s, 8, 0);
}

capn_ptr qcapn_new_BGPAfiSafi(struct capn_segment *s)
{
    return capn_new_struct(s, 16, 0);
}

capn_ptr qcapn_new_BGPPeerAfiSafi(struct capn_segment *s)
{
    return capn_new_struct(s, 8, 0);
}

void qcapn_BGPPeerAfiSafi_write(const struct peer *s, capn_ptr p, address_family_t afi, subsequent_address_family_t safi)
{
    capn_resolve(&p);
    capn_write1(p, 0, s->afc[afi][safi]);
    capn_write1(p, 1, !!(s->af_flags[afi][safi] & PEER_FLAG_SEND_COMMUNITY));
    capn_write1(p, 2, !!(s->af_flags[afi][safi] & PEER_FLAG_SEND_EXT_COMMUNITY));
    capn_write1(p, 3, !!(s->af_flags[afi][safi] & PEER_FLAG_NEXTHOP_SELF));
    capn_write1(p, 4, !!(s->af_flags[afi][safi] & PEER_FLAG_REFLECTOR_CLIENT));
    capn_write1(p, 5, !!(s->af_flags[afi][safi] & PEER_FLAG_RSERVER_CLIENT));
    capn_write1(p, 6, !!(s->af_flags[afi][safi] & PEER_FLAG_SOFT_RECONFIG));
    capn_write1(p, 7, !!(s->af_flags[afi][safi] & PEER_FLAG_AS_PATH_UNCHANGED));
    capn_write1(p, 8, !!(s->af_flags[afi][safi] & PEER_FLAG_NEXTHOP_UNCHANGED));
    capn_write1(p, 9, !!(s->af_flags[afi][safi] & PEER_FLAG_MED_UNCHANGED));
    capn_write1(p, 10, !!(s->af_flags[afi][safi] & PEER_FLAG_DEFAULT_ORIGINATE));
    capn_write1(p, 11, !!(s->af_flags[afi][safi] & PEER_FLAG_REMOVE_PRIVATE_AS));
    capn_write1(p, 12, !!(s->af_flags[afi][safi] & PEER_FLAG_ALLOWAS_IN));
    capn_write1(p, 13, !!(s->af_flags[afi][safi] & PEER_FLAG_ORF_PREFIX_SM));
    capn_write1(p, 14, !!(s->af_flags[afi][safi] & PEER_FLAG_ORF_PREFIX_RM));
    capn_write1(p, 15, !!(s->af_flags[afi][safi] & PEER_FLAG_MAX_PREFIX));
    capn_write1(p, 16, !!(s->af_flags[afi][safi] & PEER_FLAG_MAX_PREFIX_WARNING));
    capn_write1(p, 17, !!(s->af_flags[afi][safi] & PEER_FLAG_NEXTHOP_LOCAL_UNCHANGED));
    capn_write1(p, 18, !!(s->af_flags[afi][safi] & PEER_FLAG_NEXTHOP_SELF_ALL));
    capn_write8(p, 3, s->allowas_in[afi][safi]);
}

void qcapn_BGPPeerAfiSafi_read(struct peer *s, capn_ptr p, address_family_t afi, subsequent_address_family_t safi)
{
    capn_resolve(&p);
    s->afc[afi][safi] = !!(capn_read8(p, 0) & (1 << 0));
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 1));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_SEND_COMMUNITY;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_SEND_COMMUNITY;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 2));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_SEND_EXT_COMMUNITY;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_SEND_EXT_COMMUNITY;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 3));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_NEXTHOP_SELF;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_NEXTHOP_SELF;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 4));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_REFLECTOR_CLIENT;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_REFLECTOR_CLIENT;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 5));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_RSERVER_CLIENT;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_RSERVER_CLIENT;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 6));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_SOFT_RECONFIG;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_SOFT_RECONFIG;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 7));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_AS_PATH_UNCHANGED;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_AS_PATH_UNCHANGED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 0));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_NEXTHOP_UNCHANGED;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_NEXTHOP_UNCHANGED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 1));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_MED_UNCHANGED;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_MED_UNCHANGED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 2));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_DEFAULT_ORIGINATE;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_DEFAULT_ORIGINATE;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 3));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_REMOVE_PRIVATE_AS;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_REMOVE_PRIVATE_AS;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 4));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_ALLOWAS_IN;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_ALLOWAS_IN;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 5));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_ORF_PREFIX_SM;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_ORF_PREFIX_SM;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 6));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_ORF_PREFIX_RM;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_ORF_PREFIX_RM;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 1) & (1 << 7));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_MAX_PREFIX;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_MAX_PREFIX;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 2) & (1 << 0));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_MAX_PREFIX_WARNING;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_MAX_PREFIX_WARNING;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 2) & (1 << 1));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_NEXTHOP_LOCAL_UNCHANGED;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_NEXTHOP_LOCAL_UNCHANGED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 2) & (1 << 2));
      if (tmp) s->af_flags[afi][safi] |=  PEER_FLAG_NEXTHOP_SELF_ALL;
      else     s->af_flags[afi][safi] &= ~PEER_FLAG_NEXTHOP_SELF_ALL;
    }
    s->allowas_in[afi][safi] = capn_read8(p, 3);
}

void qcapn_prefix_macip_read(capn_ptr p, struct zrpc_prefix *pfx, uint8_t *index)
{
    size_t i;

    pfx->u.prefix_macip.eth_tag_id = htonl(capn_read32(p, *index));
    *index = *index + 4;
    for (i = 0; i < sizeof(struct zrpc_ethaddr); i++)
      pfx->u.prefix_macip.mac.octet[i] = capn_read8(p, *index + i);

    *index = *index + i;
    pfx->u.prefix_macip.mac_len = capn_read8(p, *index);
    *index = *index + 1;
    pfx->u.prefix_macip.ip_len = capn_read8(p, *index);
    *index = *index + 1;
    if (pfx->u.prefix_macip.ip_len == 128)
      {
        uint32_t *in6;
        for(i=0; i < 4; i++)
          {
            in6 = (uint32_t *)&(pfx->u.prefix_macip.ip.in6);
            in6+=i;
            *in6 = ntohl(capn_read32(p, *index));
            *index = *index + 4;
          }
      }
    else /* assuming 0 or 32 */
      {
        pfx->u.prefix_macip.ip.in4.s_addr = ntohl(capn_read32(p, *index));
        *index = *index + 4;
      }
}

void qcapn_prefix_macip_write(capn_ptr p, const struct zrpc_prefix *pfx, uint8_t *index)
{
    size_t i;

    capn_write32(p, *index, ntohl(pfx->u.prefix_macip.eth_tag_id));
    *index = *index + 4;
    for (i = 0; i < sizeof(struct zrpc_ethaddr); i++)
      capn_write8(p, *index + i, pfx->u.prefix_macip.mac.octet[i]);
    *index = *index + i;
    capn_write8(p, *index, pfx->u.prefix_macip.mac_len);
    *index = *index + 1;
    capn_write8(p, *index, pfx->u.prefix_macip.ip_len);
    *index = *index + 1;
    if (pfx->u.prefix_macip.ip_len == 128)
      {
        for(i=0; i < 4; i++)
          {
            uint32_t *in6;
            in6 = (uint32_t *)&(pfx->u.prefix_macip.ip.in6);
            in6+=i;
            capn_write32(p, *index, ntohl(*(in6)));
            *index = *index + 4;
          }
      }
    else /* assuming 0 or 32 */
      {
        capn_write32(p, *index, ntohl(pfx->u.prefix_macip.ip.in4.s_addr));
        *index = *index + 4;
      }
}

void qcapn_BGPVRFRoute_write(const struct bgp_api_route *s, capn_ptr p)
{
    capn_resolve(&p);
    {
        capn_ptr tempptr;
        int size = 8;

        if (s->prefix.family == AF_INET)
          size = 8;
        else if (s->prefix.family == AF_INET6)
          size = 20;
        else if (s->prefix.family == AF_L2VPN)
          {
            if (s->prefix.u.prefix_macip.ip_len == 128)
              size = 30; /* ipv6 replaced by ipv4 */
            else
              size = 18;
          }
        tempptr = capn_new_struct(p.seg, size, 0);
        capn_write8(tempptr, 0, s->prefix.family);
        capn_write8(tempptr, 1, s->prefix.prefixlen);
        if (s->prefix.family == AF_INET)
          capn_write32(tempptr, 4, ntohl(s->prefix.u.prefix4.s_addr));
        else if (s->prefix.family == AF_INET6)
          {
            size_t i;
            uint32_t *in6;
            for(i=0; i < 4; i++)
              {
                in6 = (uint32_t *)&(s->prefix.u.prefix6);
                in6+=i;
                capn_write32(tempptr, 4 + 4*i, ntohl(*(in6)));
              }
          }
        else if (s->prefix.family == AF_L2VPN)
          {
            uint8_t index = 2;

            qcapn_prefix_macip_write(tempptr, &s->prefix, &index);
          }
        capn_setp(p, 0, tempptr);
    }
    {
      qcapn_prefix_ipv4ipv6_write (p, &s->nexthop, 1);
    }
    capn_write32(p, 0, s->label);
    capn_write32(p, 4, s->ethtag);
    capn_write32(p, 8, s->l2label);
    { capn_text tp = { .str = s->esi, .len = s->esi ? strlen((const char *)s->esi) : 0 }; capn_set_text(p, 2, tp); }
    { capn_text tp = { .str = s->mac_router, .len = s->mac_router ? strlen((const char *)s->mac_router) : 0 }; capn_set_text(p, 3, tp); }
    {
      qcapn_prefix_ipv4ipv6_write (p, &s->gatewayIp, 4);
    }
}

capn_ptr qcapn_new_BGPVRFInfoIter(struct capn_segment *s)
{
    return capn_new_struct(s, 8, 0);
}

void qcapn_BGPVRFInfoIter_write(const unsigned long s, capn_ptr p, int offset)
{
    capn_resolve(&p);
    capn_write64(p, offset, s);
}

void qcapn_BGPVRFInfoIter_read(unsigned long *s, capn_ptr p, int offset)
{
    capn_resolve(&p);

    *s = capn_read64(p, offset);
}

capn_ptr qcapn_new_AfiKey(struct capn_segment *s)
{
    return capn_new_struct(s, 8, 0);
}

capn_ptr qcapn_new_BGPVRFRoute(struct capn_segment *s, uint8_t extend_by)
{
    return capn_new_struct(s, CAPN_BGPVRF_ROUTE_DEF_SIZE + extend_by, 5);
}

void qcapn_BGPVRFRoute_read(struct bgp_api_route *s, capn_ptr p)
{
    capn_resolve(&p);

    {
        capn_ptr tmp_p = capn_getp(p, 0, 1);

        s->prefix.family = capn_read8(tmp_p, 0);
        s->prefix.prefixlen = capn_read8(tmp_p, 1);

        if (s->prefix.family == AF_INET)
          {
            s->prefix.u.prefix4.s_addr = htonl(capn_read32(tmp_p, 4));
          }
        else if (s->prefix.family == AF_INET6)
          {
            size_t i;
            u_int32_t *in6;

            for(i=0; i < 4; i++)
              {
                in6 = (uint32_t *)&(s->prefix.u.prefix6);
                in6+=i;
                *in6 = htonl(capn_read32(tmp_p, 4 + 4*i));
              }
          }
        else if (s->prefix.family == AF_L2VPN)
          {
            uint8_t index = 2;

            qcapn_prefix_macip_read (tmp_p, &s->prefix, &index);
          }
    }

    {
      qcapn_prefix_ipv4ipv6_read (p, &s->nexthop, 1);
    }
    s->label = capn_read32(p, 0);
    s->ethtag = capn_read32(p, 4);
    s->l2label = capn_read32(p, 8);
    {
      char * esi = NULL;
      int len;
      capn_text tp = capn_get_text(p, 2, capn_val0);
      esi = (char *)tp.str;
      len = tp.len;
      if (esi && len != 0)
        {
          s->esi = strdup(esi);
        }
      else
        {
          s->esi = NULL;
        }
    }
    {
      char * mac_router = NULL;
      int len;
      capn_text tp = capn_get_text(p, 3, capn_val0);
      mac_router = (char *)tp.str;
      len = tp.len;
      if (mac_router && len != 0)
        {
          s->mac_router  = strdup(mac_router);
        }
      else
        {
          s->mac_router = NULL;
        }
    }
}

void qcapn_VRFTableIter_read(struct zrpc_prefix *s, capn_ptr p)
{
    capn_resolve(&p);
    
    {
        capn_ptr tmp_p = capn_getp(p, 0, 1);

        s->family = capn_read8(tmp_p, 0);
        s->prefixlen = capn_read8(tmp_p, 1);

        if (s->family == AF_INET || s->family == AF_INET6)
          {
            qcapn_prefix_ipv4ipv6_read (p, s, 0);
          }
        else if (s->family == AF_L2VPN)
          {
            uint8_t index = 2;

            qcapn_prefix_macip_read (tmp_p, s, &index);
          }
    }
}

void qcapn_VRFTableIter_write(const struct zrpc_prefix *s, capn_ptr p)
{
    capn_resolve(&p);
    
    if (s->family == AF_INET || s->family == AF_INET6)
    {
      qcapn_prefix_ipv4ipv6_write (p, s, 0);
    }
    else if (s->family == AF_L2VPN)
    {
        capn_ptr tempptr = capn_new_struct(p.seg, 30, 0);
        capn_write8(tempptr, 0, s->family);
        capn_write8(tempptr, 1, s->prefixlen);

        uint8_t index = 2;

        qcapn_prefix_macip_write(tempptr, s, &index);
        capn_setp(p, 0, tempptr);
    }
}

capn_ptr qcapn_new_VRFTableIter(struct capn_segment *s)
{
    return capn_new_struct(s, 0, 1);
}

void qcapn_BGPEventVRFRoute_read(struct bgp_event_vrf *s, capn_ptr p)
{
    uint64_t tmp;

    capn_resolve(&p);
    s->announce = capn_read8(p, 0);
    tmp = capn_read64(p, 8);
    memcpy(&s->outbound_rd.val, &tmp, 8);
    s->outbound_rd.family = AF_UNSPEC;
    s->outbound_rd.prefixlen = 64;

    {
       capn_ptr tmp_p = capn_getp(p, 0, 1);
       s->prefix.family = capn_read8(tmp_p, 0);
       s->prefix.prefixlen = capn_read8(tmp_p, 1);
       if (s->prefix.family == AF_INET)
         s->prefix.u.prefix4.s_addr = htonl(capn_read32(tmp_p, 2));
       else if (s->prefix.family == AF_INET6)
         {
           size_t i;
           u_char *in6 = (u_char*) &s->prefix.u.prefix6;

           for(i=0; i < sizeof(struct in6_addr); i++)
             in6[i] = capn_read8(tmp_p, i+2);
         }
       else if (s->prefix.family == AF_L2VPN)
          {
            uint8_t index = 2;

            qcapn_prefix_macip_read (tmp_p, &s->prefix, &index);
          }
    }

    {
      qcapn_prefix_ipv4ipv6_read (p, &s->nexthop, 1);
    }
    {
        capn_ptr tmp_p = capn_getp(p, 2, 1);
	s->label = capn_read32(tmp_p, 0);
	s->ethtag = capn_read32(tmp_p, 4);
        s->l2label = capn_read32(tmp_p, 8);
    }
    {
      const char * esi = NULL;
      int len;
      capn_text tp = capn_get_text(p, 3, capn_val0);
      esi = tp.str;
      len = tp.len;
      if (esi && len != 0)
        {
          s->esi = strdup(esi);
        }
      else
        {
          s->esi = NULL;
        }
    }
    {
      const char * mac_router = NULL;
      int len;
      capn_text tp = capn_get_text(p, 4, capn_val0);
      mac_router = tp.str;
      len = tp.len;
      if (mac_router && len != 0)
        {
          s->mac_router  = strdup(mac_router);
        }
      else
        {
          s->mac_router = NULL;
        }
    }
    {
      const char * gateway_ip = NULL;
      int len;
      capn_text tp = capn_get_text(p, 5, capn_val0);
      gateway_ip = tp.str;
      len = tp.len;
      if (gateway_ip && len != 0)
        {
          s->gatewayIp  = strdup(gateway_ip);
        }
      else
        {
          s->gatewayIp = NULL;
        }
    }
}

void qcapn_BGPEventShut_read(struct bgp_event_shut *s, capn_ptr p)
{
    capn_resolve(&p);
    
    {
      qcapn_prefix_ipv4ipv6_read (p, &s->peer, 0);
    }
    s->type = capn_read8(p, 0);
    s->subtype = capn_read8(p, 1);
}

void qcapn_BGP_read(struct bgp *s, capn_ptr p)
{
    capn_resolve(&p);
    s->as = capn_read32(p, 0);
    { capn_text tp = capn_get_text(p, 0, capn_val0); free(s->name); s->name = strdup(tp.str); }

    {
        capn_ptr tmp_p = capn_getp(p, 1, 1);
        s->router_id_static.s_addr = htonl(capn_read32(tmp_p, 0));
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 0));
      if (tmp) s->flags |=  BGP_FLAG_ALWAYS_COMPARE_MED;
      else     s->flags &= ~BGP_FLAG_ALWAYS_COMPARE_MED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 1));
      if (tmp) s->flags |=  BGP_FLAG_DETERMINISTIC_MED;
      else     s->flags &= ~BGP_FLAG_DETERMINISTIC_MED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 2));
      if (tmp) s->flags |=  BGP_FLAG_MED_MISSING_AS_WORST;
      else     s->flags &= ~BGP_FLAG_MED_MISSING_AS_WORST;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 3));
      if (tmp) s->flags |=  BGP_FLAG_MED_CONFED;
      else     s->flags &= ~BGP_FLAG_MED_CONFED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 4));
      if (tmp) s->flags |=  BGP_FLAG_NO_DEFAULT_IPV4;
      else     s->flags &= ~BGP_FLAG_NO_DEFAULT_IPV4;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 5));
      if (tmp) s->flags |=  BGP_FLAG_NO_CLIENT_TO_CLIENT;
      else     s->flags &= ~BGP_FLAG_NO_CLIENT_TO_CLIENT;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 6));
      if (tmp) s->flags |=  BGP_FLAG_ENFORCE_FIRST_AS;
      else     s->flags &= ~BGP_FLAG_ENFORCE_FIRST_AS;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 4) & (1 << 7));
      if (tmp) s->flags |=  BGP_FLAG_COMPARE_ROUTER_ID;
      else     s->flags &= ~BGP_FLAG_COMPARE_ROUTER_ID;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 0));
      if (tmp) s->flags |=  BGP_FLAG_ASPATH_IGNORE;
      else     s->flags &= ~BGP_FLAG_ASPATH_IGNORE;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 1));
      if (tmp) s->flags |=  BGP_FLAG_IMPORT_CHECK;
      else     s->flags &= ~BGP_FLAG_IMPORT_CHECK;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 2));
      if (tmp) s->flags |=  BGP_FLAG_NO_FAST_EXT_FAILOVER;
      else     s->flags &= ~BGP_FLAG_NO_FAST_EXT_FAILOVER;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 3));
      if (tmp) s->flags |=  BGP_FLAG_LOG_NEIGHBOR_CHANGES;
      else     s->flags &= ~BGP_FLAG_LOG_NEIGHBOR_CHANGES;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 4));
      if (tmp) s->flags |=  BGP_FLAG_GRACEFUL_RESTART;
      else     s->flags &= ~BGP_FLAG_GRACEFUL_RESTART;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 5));
      if (tmp) s->flags |=  BGP_FLAG_ASPATH_CONFED;
      else     s->flags &= ~BGP_FLAG_ASPATH_CONFED;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 6));
      if (tmp) s->flags |=  BGP_FLAG_ASPATH_MULTIPATH_RELAX;
      else     s->flags &= ~BGP_FLAG_ASPATH_MULTIPATH_RELAX;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 5) & (1 << 7));
      if (tmp) s->flags |=  BGP_FLAG_GR_PRESERVE_FWD;
      else    s->flags &= ~BGP_FLAG_GR_PRESERVE_FWD;
    }
    s->distance_ebgp = capn_read8(p, 6);
    s->distance_ibgp = capn_read8(p, 7);
    s->distance_local = capn_read8(p, 8);
    s->default_local_pref = capn_read32(p, 12);
    s->default_holdtime = capn_read32(p, 16);
    s->default_keepalive = capn_read32(p, 20);
    s->restart_time = capn_read32(p, 24);
    s->stalepath_time = capn_read32(p, 28);
    s->v_update_delay = capn_read16(p, 32);
    { capn_text tp = capn_get_text(p, 2, capn_val0); free(s->notify_zmq_url); s->notify_zmq_url = strdup(tp.str); }
    { capn_text tp = capn_get_text(p, 3, capn_val0); free(s->logFile); s->logFile = strdup(tp.str); }
    { capn_text tp = capn_get_text(p, 4, capn_val0); free(s->logLevel); s->logLevel = strdup(tp.str); }
}

void qcapn_BGPAfiSafi_read(struct bgp *s, capn_ptr p, address_family_t afi, subsequent_address_family_t safi)
{
    capn_resolve(&p);
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 0));
      if (tmp) s->af_flags[afi][safi] |=  BGP_CONFIG_DAMPENING;
      else     s->af_flags[afi][safi] &= ~BGP_CONFIG_DAMPENING;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 1));
      if (tmp) s->af_flags[afi][safi] |=  BGP_CONFIG_ASPATH_MULTIPATH_RELAX;
      else     s->af_flags[afi][safi] &= ~BGP_CONFIG_ASPATH_MULTIPATH_RELAX;
    }
    { bool tmp;
      tmp = !!(capn_read8(p, 0) & (1 << 2));
      if (tmp) s->af_flags[afi][safi] |=  BGP_CONFIG_MULTIPATH;
      else     s->af_flags[afi][safi] &= ~BGP_CONFIG_MULTIPATH;
    }
}

void qcapn_prefix_ipv4ipv6_write (capn_ptr p, const struct zrpc_prefix *pfx, uint8_t index)
{
  capn_ptr tempptr;
  int size = 8;

  if (pfx->family == AF_INET)
    size = 8;
  else if (pfx->family == AF_INET6)
    size = 20;

  tempptr = capn_new_struct(p.seg, size, 0);
  capn_write8(tempptr, 0, pfx->family);
  capn_write8(tempptr, 1, pfx->prefixlen);
  if (pfx->family == AF_INET)
    {
      capn_write32(tempptr, 4, ntohl(pfx->u.prefix4.s_addr));
    }
  else if (pfx->family == AF_INET6)
    {
      size_t i;
      uint32_t *in6;
      for(i=0; i < 4; i++)
        {
          in6 = (uint32_t *)&(pfx->u.prefix6);
          in6+=i;
          capn_write32(tempptr, 4 + 4*i, ntohl(*(in6)));
        }
    }
  capn_setp(p, index, tempptr);
}

void qcapn_prefix_ipv4ipv6_read(capn_ptr p, struct zrpc_prefix *pfx, uint8_t index)
{
  capn_ptr tmp_p = capn_getp(p, index, 1);
  pfx->family = capn_read8(tmp_p, 0);
  pfx->prefixlen = capn_read8(tmp_p, 1);

  if (pfx->family == AF_INET)
    {
      pfx->u.prefix4.s_addr = htonl(capn_read32(tmp_p, 4));
    }
  else if (pfx->family == AF_INET6)
    {
      size_t i;
      u_int32_t *in6;
      
      for(i=0; i < 4; i++)
        {
          in6 = (uint32_t *)&(pfx->u.prefix6);
          in6+=i;
          *in6 = htonl(capn_read32(tmp_p, 4 + 4*i));
        }
    }
}
