# Environment variable plugin

## Installation

Follow the [instructions](https://docs.halon.io/manual/comp_install.html#installation) in our manual to add our package repository and then run the below command.

### Ubuntu

```
apt-get install halon-extras-env
```

### RHEL

```
yum install halon-extras-env
```

## Exported functions

### getenv(name)

Get an environment variable as a `string`. If not found `none` is returned.

**Params**

- name `string` - The environment variable name

**Returns**

The variable as a `string`. If not found `none` is returned.
